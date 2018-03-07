#include <iostream>
#include <string>

using namespace std;

class Game{

public:
	void welcomeMessage(int check){
		cout<<"Welcome to Word Jumble!"<<endl<<endl;
		cout<<"If you would like to quit at any time, type 'quit'"<<endl;
		cout<<"If you would like to use a lifeline at any time, type 'swap', You can use it "<< check<<" more times."<<endl;

	}

	void mainLoop(string& tester, string& tester2, int&alsotest, bool& x){
	cout<<"You have to solve "<<tester2<<endl<<"You have " << (3-alsotest)<<" attempt(s) left"<<endl;
	string guess;
	cin >> guess;

	if (guess == tester){
		x = true;
	}

	else{
		alsotest++;
	}



}

};
