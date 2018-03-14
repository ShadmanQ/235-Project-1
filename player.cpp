#include "player.h"

using namespace std;

int aPlayer::load(){

	ifstream initialStats;
	int firststat;
	char accept;
	initialStats.open("saveFile.tsv");
	if(initialStats){
		cout <<"It seems there's a previous file. Would you like to load it? (type y or n)"<<endl;
		cin >> accept;
		if (accept == 'y'){
			initialStats>>firststat;
			cout<<"Let's pick up from where you left off! You currently have "<< firststat <<"wins"<<endl;
			return firststat;
		}
		if (accept == 'n'){
			return 0;
		}
	}
	else{
		cout<<"No previous save file found. Starting a new game!"<<'\n'<<endl;
		return 0;
	}
}


void aPlayer::allTimeStats(int allWins, vector<string> cor){

	ofstream allTime;
	allTime.open("allTime.txt");
	allTime << allWins;
	for(int i = 0; i < unsigned(cor.size()); i++){
		allTime<<cor[i]<<'\n';
	}
}
void aPlayer::outFile(int outwins, vector<string> cor){
	ofstream stats;
	stats.open("saveFile.tsv");
	stats <<outwins<<endl;
	for (int i = 0; i < unsigned(cor.size()); i++){
		stats << cor[i]<<'\n';
	}
	stats.close();
	}
