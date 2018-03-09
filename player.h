#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <fstream>

using namespace std;

class aPlayer{
private:

public:
void newSession(){
	ifstream initialstats;
	int firststat;
}

void outFile(int outwins){
	ofstream stats;
	stats.open("playerstats.tsv");
	stats <<outwins<<endl;
	stats.close();
	}
};
#endif /* PLAYER_H */