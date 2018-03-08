/**
Shadman Quazi
CSCI 235 Project 1: World Jumble

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "player.h"
#include "gameLogic.h"

int main(){

Player player1;
Game newGame;
bool win = false;
bool lifeAllowed = true;
int guesses = 0;
int lifelines = 5;

std::string a;
std::ifstream teststream;

std::vector<std::string> testVec;

teststream.open("test.txt");

while(teststream>>a){
	testVec.push_back(a);
}

newGame.welcomeMessage(); // message explain the rules of the game to the player


std::string wordToGuess = newGame.chooseAWord(testVec);
std::string gameWord= wordToGuess;

newGame.jumbler(gameWord);

while(!win && (guesses < 3)){

	newGame.mainLoop(wordToGuess,gameWord, guesses, win, testVec, lifelines, lifeAllowed);
	}

if (guesses == 3){
	std::cout<<"Oh Well, you lose :("<<std::endl;
	}

else{
	player1.victory("tbd");
	}

return 0;
}
