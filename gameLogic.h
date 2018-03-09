#ifndef GAMELOGIC_H
#define GAMELOGIC_H


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "player.h"

using namespace std;

class Game{

private:
int playerGuesses = 0;
int wins = 0;
int lifeline = 5;
bool win = false;
bool lifeAllowed = true;
bool gameOver = false;
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

	//parses vector for word, makes player guess the word
	//@param vector loaded in from the main.cpp file 
	void mainLoop(vector<string> vec, aPlayer play){
		currentWord = chooseAWord(vec);
		jumbledWord = currentWord;
		jumbler(jumbledWord);

		while(!win && playerGuesses < 3){
			if (gameOver){
				break;
			}
			
			if (playerGuesses == 2){
				lifeAllowed = false;
			}
			cout<<"This word is "<<difficulties[difficulty]<<endl;
			cout<<"You have to solve "<<jumbledWord<<endl<<"You have " << (3-playerGuesses)<<" attempt(s) left"<<endl;
			string guess;
			cin >> guess;
			if (guess == currentWord){
				win = true;
				victory(vec, play);
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
				quit(play);
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
	
	void victory(vector<string> vec, aPlayer p){
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
			quit(p);
		}
	}

	void loss(string word){
		cout<<"Sorry! Your word was "<<word<<endl;
	}

	/**
	@param string t, to compare to the upper bound and lower bound of a particular difficulty
	@return true if length of the word is between upper/lower bound, i.e. appropriate difficulty
	*/
	bool verifyDifficulty(string t){
		if (t.size() >= lowerbound && t.size() <= upperbound){
			return true;
		}
		else{
			return false;
		}

	}

	/**
	*/
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

	void quit(aPlayer p){
		cout<<"I hope you had fun!"<<endl;
		cout<<"Your final total is "<< wins << " wins."<<endl;
		p.outfile(wins);
		gameOver = true;
	}
};
#endif /* GAMELOGIC_H*/
