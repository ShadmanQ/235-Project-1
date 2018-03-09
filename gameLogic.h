#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Game{

private:
int playerGuesses = 0;
int wins = 0;
int lifeline = 5;
bool win = false;
bool lifeAllowed = true;
int difficulty = 0;
string currentWord ="";
string jumbledWord = "";
string difficulties[4] = {"EASY","MEDIUM","HARD", "VERY HARD"};
int lowerbound = 3;
int upperbound = 5;

public:
	//welcomes the player to the game, explains the rules
	void welcomeMessage(){
		cout<<"Welcome to Word Jumble!"<<endl<<endl;
		cout<<"If you would like to quit at any time, type 'quit'"<<endl;
		cout<<"If you would like to use a lifeline at any time, type 'swap'"<<endl<<
		"You can use it 5 times throughout the game."<<endl<<endl<<endl;
	}

	//main game logic, kills 
	void mainLoop(vector<string> vec){
		currentWord = chooseAWord(vec);
		jumbledWord = currentWord;
		jumbler(jumbledWord);
	while(!win && playerGuesses < 3){
		if (playerGuesses == 2){
			lifeAllowed = false;
		}
		cout<<"This word is "<<difficulties[difficulty]<<endl;
		cout<<"You have to solve "<<jumbledWord<<endl<<"You have " << (3-playerGuesses)<<" attempt(s) left"<<endl;
		string guess;
		cin >> guess;
		if (guess == currentWord){
			win = true;
			victory(vec);
		}

		else if (guess == "swap"){
			if (lifeAllowed){
				lifeLine(currentWord, jumbledWord,lifeline, vec);
			}

		else{
			cout<<"Can't let you do that!"<<endl;
		}
	}
		else if (guess == "quit"){
			cout<<"I'ma quit"<<endl;
		}

		else{
			playerGuesses++;
		}

	}

	if (playerGuesses == 3){
		loss(currentWord);
	}

	}

	void lifeLine(string& oldWord, string& oldscramble,int& life, vector<string> vec){
		oldWord = chooseAWord(vec);
		oldscramble = oldWord;
		jumbler(oldscramble);
		lifeline--;
		cout << "You have "<<life<<" lifelines left"<<endl;

	}
	
	string chooseAWord(vector<string> vec){
		string thisThing = "";
		while (!verifyDifficulty(thisThing)){
		srand(time(0));
		int mod = vec.size();
		int index = rand() % mod;

		thisThing = vec[index];
		}
		return thisThing;
	}

	void jumbler(string& normalWord){
		random_shuffle(normalWord.begin(),normalWord.end());
	}
	
	void victory(vector<string> vec){
		wins++;
		cout<<"Awesome! You figured out that " <<jumbledWord<<" was actually "<<currentWord<<"!"<<endl;
		cout<<"You now have "<<wins<<" win(s)"<<endl;
		cout<<"Would you like to continue? (type y or n)"<<endl;
		char cont;
		cin >> cont;

		if (cont == 'y'){
			reset(vec);
		}
		else{
			cout <<"Okay, hope you had fun!"<<endl;
		}
	}

	void loss(string word){
		cout<<"Sorry! Your word was "<<word<<endl;
	}

	bool verifyDifficulty(string t){
		if (t.size() >= lowerbound && t.size() <= upperbound){
			return true;
		}
		else{
			return false;
		}

	}
	void reset(vector<string> bec){
		if ((wins % 3 == 0) && wins<13){
			adjustDifficulty();
		}
		playerGuesses = 0;
		win = false;
		lifeAllowed = true;
		currentWord = chooseAWord(bec);
		jumbledWord = currentWord;
		jumbler(jumbledWord);
	}
	void adjustDifficulty(){
		difficulty++;
		lowerbound+=3;
		upperbound+=3;
		if (difficulty == 3){
			upperbound = 182;
		}

	}
};
