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
int recordWins = 0;
int lifeline = 5;
int lowerbound = 3;
int upperbound = 5;
int difficulty = 0;
bool win = false;
bool lifeAllowed = true;
bool gameOver = false;
string currentWord ="";
string jumbledWord = "";
string guess;
std::vector<string> correctWords;

public:
	//welcomes the player to the game, explains the rules
	void welcomeMessage(aPlayer p);

	//parses vector for word, makes player guess the word
	//@param vector loaded in from the main.cpp file 
	void mainLoop(vector<string> vec, aPlayer play);

	/**
	@param oldWord, string to manipulate into new word
	@param oldscramble, jumbled string that gets rejumbled
	@param life, # of lifelines allowed
	@param vec, vector of strings from main cpp file
	*/
	void lifeLine (vector<string> vec);
	
	/**
	@param vec, vector of string from main cpp file
	*/
	string chooseAWord(vector<string> vec);
	
	/**
	creates jumbled word from normal word
	*/
	void jumbler();
	/**
	@pre player has successfully guessed a word
	@param vec, vector of strings to choose the next word
	@param, p, player object to invoke the output function if needed
	@param vicString, string object for the winning word

	*/

	void victory(vector<string> vec, aPlayer p);

	/**
	@pre, player was unable to guess the jumbledWord in 3 guesses or less
	@param word, i.e. the world that player
	@post, program outputs stats to file and exis program.
	*/
	void loss(aPlayer p);

	/**
	@param string t, to compare to the upper bound and lower bound of a particular difficulty
	@return true if length of the word is between upper/lower bound, i.e. appropriate difficulty
	*/
	bool verifyDifficulty(string t);


	/**
	@return true if word picked by chooseaWord function has already been chosen in a prior round
	*/
	bool checkifredunant ();

	/**
	
	*/
	void reset(vector<string> vec, aPlayer p);
/**
	*/
	void adjustDifficulty();
/**
	*/
	void quit(aPlayer p);
};
#endif /* GAMELOGIC_H*/
