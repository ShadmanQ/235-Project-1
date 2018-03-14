#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class aPlayer{
private:

public:
int load();
void allTimeStats(int allWins, vector<string> cor);
void outFile(int outwins, vector<string> cor);
};
#endif /* PLAYER_H */
