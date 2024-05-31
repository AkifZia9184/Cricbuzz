#ifndef TEAM_H
#define TEAM_H
# include <iostream>
#include "player.h"
using namespace std;
class Team:public Player
{
public:
	string teamName;
	int teamRankingT20[6], teamRankingODI[6], teamRankingTest[6], No_ofPlayers, TotalMatchesWon[6], Total_Matches_Lost[6];
	string captan,wicketkeeper, coach, admin_username, admin_password;
public:
	Team();
	void addPlayer();
	void removePlayer();
	void searchPlayer();
	void updatePlayer();
	void displayMatches();
	void updateCaptain();
	void updateCoach();
	void displayTeam();
	void ViewStats();


};
#endif
