#include "gameLogic.h"
#include "player.h"

using namespace std;

void Game::welcomeMessage(aPlayer p){
	//welcome message from the game, explains the world
	cout<<"Welcome to Word Jumble!"<<endl<<endl;
	cout<<"If you would like to quit at any time, type 'quit'"<<endl;
	cout<<"If you would like to use a lifeline at any time, type 'swap'"<<endl<<
	"You can use it 5 times throughout the game."<<'\n'<<'\n'<<endl;
	cout<<"The current record for wins is " << wins <<endl;
	wins = p.load();
	adjustDifficulty();//sets difficulty to level 0
}



void Game::mainLoop(vector<string> vec, aPlayer play)
{
	//picks word from vector of words
	currentWord = chooseAWord(vec);

	//assigns and modifies jumbledWord based on the current word
	jumbledWord = currentWord;
	jumbler();

	while(!win && playerGuesses < 3){

		if (playerGuesses == 2){
			lifeAllowed = false; // locks up lifelfine functionality
		}
		cout<<"You are currently on level "<<difficulty<<endl;
		cout<<"You have to solve "<<jumbledWord<<endl<<"You have " << (3-playerGuesses)<<" attempt(s) left"<<endl;
		cin >> guess;
		if (guess == currentWord){
			win = true;// i.e. win condition is met
		}

		else if (guess == "swap"){
			if (lifeAllowed){//prelimnary check to see if allowed to use
				lifeLine(vec);
			}

		else{
			cout<<"Can't let you do that!"<<endl;//returns to make cin statement
			}
		}

		else if (guess == "quit"){//quits the game based on user input
			quit(play);
		}

		else{
			playerGuesses++;//gets closer to loss condition
		}

	}	

	if (playerGuesses == 3){//reaches the loss condition
		loss(play);
	}

	// is only executed when win is true
	victory (vec,play);

}

string Game::chooseAWord(vector<string> vec){
	string thisThing = "";

	while (!verifyDifficulty(thisThing)){
		srand(time(0));//random seed based on computer clock
		int mod = vec.size();
		int index = rand() % mod; //chooses random number based on size of word vector

		thisThing = vec[index];

	}
	return thisThing;
}


void Game::lifeLine(vector<string> vec){
	currentWord= chooseAWord(vec);//effectively swaps words
	jumbler();
	lifeline--;
	cout << "You have "<<lifeline<<" lifelines left"<<endl;
}
	

	
void Game::jumbler(){//used random_shuffle function from algorithm library
	random_shuffle(jumbledWord.begin(),jumbledWord.end());
}

void Game::victory(vector<string> vec, aPlayer p){
	wins++;
	correctWords.push_back(currentWord);
	cout<<"Awesome! You figured out that " <<jumbledWord<<" was actually "<<currentWord<<"!"<<endl;
	cout<<"You now have "<<wins<<" win(s)"<<endl;
	cout<<"Would you like to continue? (type y or n)"<<endl;
	char cont;
	cin >> cont;//to decide what the next step

	if (cont == 'y'){
		reset(vec,p);
	}

	else if (cont == 'n'){
		quit(p);
	}

	else {
		cout << "not a valid input, try again"<<endl;
	}
}

void Game::loss(aPlayer p){
	cout<<"Sorry! Your word was "<<currentWord<<endl;
	//because loss condition was achieved, game automatically 
	// quits
	quit(p);
}

bool Game::verifyDifficulty(string t){
	//makes sure the word is within a preset max and min lenth
	//this is set by AdjustDifficulty
	if ((t.size() >= lowerbound) && (t.size() <= upperbound)){
		return true;
	}
	else{
		return false;
	}

}

bool Game::checkifredunant (){

	if (correctWords.size() == 0){
		return false;
	}
	else{
		for (int i = 0; i<=correctWords.size(); i++){
			if ( currentWord == correctWords[i])
			{
				return true;
			}
		}
	}
	return false;
}
	

void Game::reset(vector<string> vec, aPlayer p){
	adjustDifficulty();
	playerGuesses = 0;
	win = false;
	lifeAllowed = true;
	mainLoop(vec, p);
}

void Game::adjustDifficulty(){
	int check = wins/3; 
	//because advancing of level is determined every 3 rounds
		
	if (check > difficulty){
		difficulty=check;
		lowerbound= 3 + (3*difficulty);
		upperbound= 5 + (3*difficulty);
		}
}

void Game::quit(aPlayer p){
	//informs player of final game stats
	cout<<"Your final total is "<< wins << " wins."<<endl;
	cout<<"Hope you enjoyed playing!"<<endl;
	p.outFile(wins, correctWords);//invokes output file function
}
