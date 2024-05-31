# include <iostream>
using namespace std;
class Match
{
private:
	string Team1, Team2, venue, matchType, tournamentName, Commentators, umpires, matchstatus, Teams[8], venues[3];
	int sdate,edate;
public:
	Match();
	void conductMatch();
	void scheduleMatch();
	void updateWorldRecords();
	void displayUpcomingMatches();
	void displayRecentMatches();
	void conductTournament();

};
