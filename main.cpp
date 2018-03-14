/**
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

std::string a;
std::ifstream teststream;

std::vector<std::string> inputVec;

teststream.open("wordList.txt");

while(teststream>>a){
	inputVec.push_back(a);
}

newGame.welcomeMessage(player1); // message explain the rules of the game to the player

newGame.mainLoop(inputVec, player1);


return 0;
}
