#ifndef Player_H
#define Player_H
# include <iostream>
using namespace std;
class Player
{
public:
	//data members
	int size = 16;
	string* Oname = new string[size];
	string *Tname = new string[size];
	string *TTname=new string[size];
	float average[15];
	int rankingT20[15], rankingODI[15], rankingTest[15], totalRuns[15], matchesPlayed[15], totalWickets[15], shirtNumber[15], notouts[15], noOfHundreds[15], noOfFifties[15];
public:
	//constructor
	Player();

	//member functions
	virtual void addPlayer()=0;
	virtual void removePlayer()=0;
	virtual void searchPlayer()=0;
	virtual void updatePlayer() = 0;
};
#endif
