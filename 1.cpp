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
#include "player.h"

int main(){

Player player1;
bool win = false;
int guesses = 0;
int lifelines = 5;

player1.display();

std::string a;
std::ifstream teststream;

std::vector<std::string> testVec;

teststream.open("test.txt");

while(teststream>>a){
	testVec.push_back(a);
}

srand(time(0));

int mod = testVec.size();
int index = rand() % mod;


std::cout<<testVec[index]<<std::endl;

while(!win && (guesses < 3)){

	std::string wordToGuess = testVec[index];
	std::string guess;

	std::cout<<"Hello! Please guess what word you have"<<std::endl;
	std::cin >> guess;

	if (guess == wordToGuess){
	win = true;
	}

	else{
	guesses++;
	}

}

if (guesses == 3){
std::cout<<"Oh Well, you lose :("<<std::endl;

}

else{

std::cout<<"You win!"<<std::endl;
}
return 0;
}
