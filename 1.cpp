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
int guesses = 0;
int lifelines = 5;

std::string a;
std::ifstream teststream;

std::vector<std::string> testVec;

teststream.open("test.txt");

while(teststream>>a){
	testVec.push_back(a);
}

newGame.welcomeMessage(lifelines);

srand(time(0));

int mod = testVec.size();
int index = rand() % mod;

std::string scramble = testVec[index];
random_shuffle(scramble.begin(),scramble.end());

while(!win && (guesses < 3)){

	std::string wordToGuess = testVec[index];
	newGame.mainLoop(wordToGuess, scramble, guesses, win);
}

if (guesses == 3){
	std::cout<<"Oh Well, you lose :("<<std::endl;
}

else{
	player1.victory();
}

return 0;
}
