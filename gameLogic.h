#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Game{

public:
	void welcomeMessage(){
		cout<<"Welcome to Word Jumble!"<<endl<<endl;
		cout<<"If you would like to quit at any time, type 'quit'"<<endl;
		cout<<"If you would like to use a lifeline at any time, type 'swap', You can use it 5 times throughout the game."<<endl<<endl<<endl;

	}

	void mainLoop(string& tester, string& tester2, int&alsotest, bool& x, vector<string> vec, int& life, bool& allowance){
	cout<<"You have to solve "<<tester2<<endl<<"You have " << (3-alsotest)<<" attempt(s) left"<<endl;
	string guess;
	cin >> guess;

	if (guess == tester){
		x = true;
	}

	else if (guess == "swap"){
		lifeLine(tester, tester2,life, vec);
	}

	else if (guess == "quit"){
		cout<<"I'ma quit"<<endl;
	}

	else{
		alsotest++;
	}
	
	}

	void lifeLine(string& oldWord, string& oldscramble,int& life, vector<string> vec){
		oldWord = chooseAWord(vec);
		oldscramble = oldWord;
		jumbler(oldscramble);
		life--;
		cout << "You have "<<life<<" lifelines left"<<endl;

	}
	
	string chooseAWord(vector<string> vec){
		srand(time(0));
		int mod = vec.size();
		int index = rand() % mod;

		string thisThing = vec[index];
		return thisThing;
	}

	void jumbler(string& test){
		random_shuffle(test.begin(),test.end());
	}
};
