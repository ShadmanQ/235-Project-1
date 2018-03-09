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

aPlayer player1;
Game newGame;
bool win = false;
bool lifeAllowed = true;
int guesses = 0;
int lifelines = 5;
int difficulty = 0;

std::string a;
std::ifstream teststream;

std::vector<std::string> testVec;

teststream.open("test.txt");

while(teststream>>a){
	testVec.push_back(a);
}

newGame.welcomeMessage(); // message explain the rules of the game to the player

newGame.mainLoop(testVec, player1);


return 0;
}
