#include <iostream>

using namespace std;

class Player{
int wins = 0;
int guesses = 0;
public:
void display(){
cout<<"Player wins:"<<wins<<std::endl;
}

void victory(string word){
wins++;
cout<<"That's right! your word was " << word<<endl;
cout<<"Player now has "<<wins<<" win(s)."<<endl;
}
};
