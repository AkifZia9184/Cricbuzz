//Player.h (Abstract Class):
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

//Player.cpp
# include "player.h"
//constructor
Player::Player()
{
	*average = 0;
	*matchesPlayed = 0;
	*Oname = " ";
	*noOfFifties = 0;
	*noOfHundreds = 0;
	*notouts = 0;
	*rankingODI = 0;
	*rankingT20 = 0;
	*rankingTest = 0;
	*shirtNumber = 0;
	*totalRuns = 0;
	*totalWickets = 0;
}



//Team.h:
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



//Team.cpp:
# include <fstream>
# include <string>
# include <iomanip>
# include <Windows.h>
# include "Team.h"
//# include <iostream>
using namespace std;
Team::Team()
{
	this->admin_password = " ";
	this->admin_username = " ";
	this->captan = " ";
	this->coach = " ";
	this->No_ofPlayers = 0;
	this->teamName = " ";
	*teamRankingODI = 0;
	*teamRankingT20 = 0;
	*teamRankingTest = 0;
	*TotalMatchesWon = 0;
	*Total_Matches_Lost = 0;
}
void Team:: addPlayer()
{
	string *temp = new string[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = Oname[i];
		}
		size++;
		Oname = new string[size];
		for (int i = 0; i < size-1; i++)
		{
			Oname[i] = temp[i];
		}
		for (int i = 0; i < size-1; i++)
		{
			temp[i] = Tname[i];
		}
		Tname = new string[size];
		for (int i = 0; i < size - 1; i++)
		{
			Tname[i] = temp[i];
		}
		for (int i = 0; i < size-1; i++)
		{
			temp[i] = TTname[i];
		}
		TTname = new string[size];
		for (int i = 0; i < size - 1; i++)
		{
			TTname[i] = temp[i];
		}
		fstream pak;
		int choice;
		string name;
		cout << " In which team you want to add player " << endl;
		cout << "1:Pakistan" << endl;
		cout << "2:India" << endl;
		cout << "3:England" << endl;
		cout << "4:Austrailia" << endl;
		cout << "5:South Africa" << endl;
		cout << "6:New Zeland" << endl;
		cin >> choice;
		if (choice == 1)
		{
			teamName = "PAKISTAN";
			pak.open("pak.txt");
		}
		if (choice == 2)
		{
			teamName = "INDIA";
			pak.open("india.txt");
		}
		if (choice == 3)
		{
			teamName = "ENGLAD";
			pak.open("eng.txt");
		}
		if (choice == 4)
		{
			teamName = "AUSTRALIA";
			pak.open("aus.txt");
		}
		if (choice == 5)
		{
			teamName = "SouthAfrca";
			pak.open("sa.txt");
		}
		if (choice == 6)
		{
			teamName = "NewZeland";
			pak.open("nz.txt");
		}
		int i = 0, j = 0, k = 0;
		while (!pak.eof())
		{
			if (i >= 0 && i < 15)
			{
				getline(pak, Tname[i]);
				if (i == 0)
				{
					captan = Tname[i];
				}
				if (i == 1)
				{
					wicketkeeper = Tname[i];
				}
				i++;
			}
			if (i >= 15 && i < 30)
			{
				getline(pak, Oname[j]);
				if (j == 0)
				{
					captan = Oname[j];
				}
				if (j == 1)
				{
					wicketkeeper = Oname[j];
				}
				j++;
				i++;
			}
			if (i >= 30 && i <= 45)
			{
				getline(pak, TTname[k]);
				if (k == 0)
				{
					captan = TTname[k];
				}
				if (k == 1)
				{
					wicketkeeper = TTname[k];
				}
				if (k == 15)
				{
					coach = TTname[k];
					TTname[k] = ' ';
				}
				k++;
				i++;
			}

		}
		pak.close();
		system("cls");
		displayTeam();
		cout << "enter the name of player you want to add" << endl;
		getline(cin >> ws, Tname[size-1]);
		system("pause");
		cout << "updated squad " << endl;
		displayTeam();
}
void Team::ViewStats()
{
	fstream pak;
	float f;
	int choice=0;
	int a;
	pak.open("teamstat.txt");
	int i = 0;
	while (!pak.eof())
	{
		pak >> a;
		teamRankingT20[i] = a;
		pak >> a;
		teamRankingODI[i] = a;
		pak >> a;
		teamRankingTest[i] = a;
		pak >> a;
		TotalMatchesWon[i] = a;
		pak >> a;
		Total_Matches_Lost[i] = a;
		i++;
	}
	pak.close();
	cout << " you want to see the stats of: " << endl;
	cout << " 1:Team" << endl;
	cout << " 2:Player" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		while (choice != 7)
		{
			system("cls");
			cout << " which team  you want to see stats " << endl;
			cout << "1:Pakistan" << endl;
			cout << "2:India" << endl;
			cout << "3:England" << endl;
			cout << "4:Austrailia" << endl;
			cout << "5:South Africa" << endl;
			cout << "6:New Zeland" << endl;
			cout << "7:Go back " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << " T20 Ranking of Pakistan: " << teamRankingT20[0] << endl;
				cout << " ODI Ranking of Pakistan: " << teamRankingODI[0] << endl;
				cout << " Test Ranking of Pakistan: " << teamRankingTest[0] << endl;
				cout << " Total matches Won: " << TotalMatchesWon[0] << endl;
				cout << " Total matches Lost: " << Total_Matches_Lost[0] << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				cout << " T20 Ranking of India: " << teamRankingT20[1] << endl;
				cout << " ODI Ranking of India: " << teamRankingODI[1] << endl;
				cout << " Test Ranking of India: " << teamRankingTest[1] << endl;
				cout << " Total matches Won: " << TotalMatchesWon[1] << endl;
				cout << " Total matches Lost: " << Total_Matches_Lost[1] << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				cout << " T20 Ranking of England: " << teamRankingT20[2] << endl;
				cout << " ODI Ranking of Endland: " << teamRankingODI[2] << endl;
				cout << " Test Ranking of England: " << teamRankingTest[2] << endl;
				cout << " Total matches Won: " << TotalMatchesWon[2] << endl;
				cout << " Total matches Lost: " << Total_Matches_Lost[2] << endl;
				system("pause");
				system("cls");
				break;
			case 4:
				cout << " T20 Ranking of Australia: " << teamRankingT20[3] << endl;
				cout << " ODI Ranking of Austrailia: " << teamRankingODI[3] << endl;
				cout << " Test Ranking of Austrailia: " << teamRankingTest[3] << endl;
				cout << " Total matches Won: " << TotalMatchesWon[3] << endl;
				cout << " Total matches Lost: " << Total_Matches_Lost[3] << endl;
				system("pause");
				system("cls");
				break;
			case 5:
				cout << " T20 Ranking of SouthAfrica: " << teamRankingT20[4] << endl;
				cout << " ODI Ranking of SouthAfrica: " << teamRankingODI[4] << endl;
				cout << " Test Ranking of SouthAfrica: " << teamRankingTest[4] << endl;
				cout << " Total matches Won: " << TotalMatchesWon[4] << endl;
				cout << " Total matches Lost: " << Total_Matches_Lost[4] << endl;
				system("pause");
				system("cls");
				break;
			case 6:
				cout << " T20 Ranking of NewZeland: " << teamRankingT20[5] << endl;
				cout << " ODI Ranking of NewZeland: " << teamRankingODI[5] << endl;
				cout << " Test Ranking of NewZeland: " << teamRankingTest[5] << endl;
				cout << " Total matches Won: " << TotalMatchesWon[5] << endl;
				cout << " Total matches Lost: " << Total_Matches_Lost[5] << endl;
				system("pause");
				system("cls");
				break;
			case 7:
				break;
			}
		}
		break;
	case 2:

		pak.open("stats.txt");
		int a = 0;
		while (!pak.eof())
		{
			pak >> f;
			shirtNumber[a] = f;
			pak >> f;
			average[a] = f;
			pak >> f;
			rankingT20[a] = f;
			pak >> f;
			rankingODI[a] = f;
			pak >> f;
			rankingTest[a] = f;
			pak >> f;
			totalRuns[a] = f;
			pak >> f;
			matchesPlayed[a] = f;
			pak >> f;
			totalWickets[a] = f;
			a++;
		}
		pak.close();
		string name;
		cout << " which team player you want to see stats " << endl;
		cout << "1:Pakistan" << endl;
		cout << "2:India" << endl;
		cout << "3:England" << endl;
		cout << "4:Austrailia" << endl;
		cout << "5:South Africa" << endl;
		cout << "6:New Zeland" << endl;
		cin >> choice;
		if (choice == 1)
		{
			teamName = "PAKISTAN";
			pak.open("pak.txt");
		}
		if (choice == 2)
		{
			teamName = "INDIA";
			pak.open("india.txt");
		}
		if (choice == 3)
		{
			teamName = "ENGLAD";
			pak.open("eng.txt");
		}
		if (choice == 4)
		{
			teamName = "AUSTRALIA";
			pak.open("aus.txt");
		}
		if (choice == 5)
		{
			teamName = "SouthAfrca";
			pak.open("sa.txt");
		}
		if (choice == 6)
		{
			teamName = "NewZeland";
			pak.open("nz.txt");
		}
		int i = 0, j = 0, k = 0;
		while (!pak.eof())
		{
			if (i >= 0 && i < 15)
			{
				getline(pak, Tname[i]);
				if (i == 0)
				{
					captan = Tname[i];
				}
				if (i == 1)
				{
					wicketkeeper = Tname[i];
				}
				i++;
			}
			if (i >= 15 && i < 30)
			{
				getline(pak, Oname[j]);
				if (j == 0)
				{
					captan = Oname[j];
				}
				if (j == 1)
				{
					wicketkeeper = Oname[j];
				}
				j++;
				i++;
			}
			if (i >= 30 && i <= 45)
			{
				getline(pak, TTname[k]);
				if (k == 0)
				{
					captan = TTname[k];
				}
				if (k == 1)
				{
					wicketkeeper = TTname[k];
				}
				if (k == 15)
				{
					coach = TTname[k];
					TTname[k] = ' ';
				}
				k++;
				i++;
			}

		}
		pak.close();
		system("cls");
		displayTeam();
		cout << " enter the name of the player you want to see stats " << endl;
		getline(cin >> ws, name);
		for (int i = 0; i < size; i++)
		{
			int option;
			if (name == Tname[i])
			{
				cout << " current stats of " << name << endl;
				cout << " T20 Ranking " << rankingT20[i] << endl;
				cout << " ODI Ranking " << rankingODI[i] << endl;
				cout << " Test Ranking " << rankingTest[i] << endl;
				cout << " Shirt number " << shirtNumber[i] << endl;
				cout << " Average " << average[i] << endl;
				cout << " Total Runs " << totalRuns[i] << endl;
				cout << " Matches palyed " << matchesPlayed[i] << endl;
				cout << " Total Wickets " << totalWickets[i] << endl;
				system("pause");
			}
		}
		break;
	}
}
void Team::removePlayer()
{
	string str;
	fstream pak;
	int choice;
	string name;
	cout << " From which team you want to remove player " << endl;
	cout << "1:Pakistan" << endl;
	cout << "2:India" << endl;
	cout << "3:England" << endl;
	cout << "4:Austrailia" << endl;
	cout << "5:South Africa" << endl;
	cout << "6:New Zeland" << endl;
	cin >> choice;
	if (choice == 1)
	{
		teamName = "PAKISTAN";
		pak.open("pak.txt");
	}
	if (choice == 2)
	{
		teamName = "INDIA";
		pak.open("india.txt");
	}
	if (choice == 3)
	{
		teamName = "ENGLAD";
		pak.open("eng.txt");
	}
	if (choice == 4)
	{
		teamName = "AUSTRALIA";
		pak.open("aus.txt");
	}
	if (choice == 5)
	{
		teamName = "SouthAfrca";
		pak.open("sa.txt");
	}
	if (choice == 6)
	{
		teamName = "NewZeland";
		pak.open("nz.txt");
	}
	int i = 0, j = 0, k = 0;
	while (!pak.eof())
	{
		if (i >= 0 && i < 15)
		{
			getline(pak, Tname[i]);
			if (i == 0)
			{
				captan = Tname[i];
			}
			if (i == 1)
			{
				wicketkeeper = Tname[i];
			}
			i++;
		}
		if (i >= 15 && i < 30)
		{
			getline(pak, Oname[j]);
			if (j == 0)
			{
				captan = Oname[j];
			}
			if (j == 1)
			{
				wicketkeeper = Oname[j];
			}
			j++;
			i++;
		}
		if (i >= 30 && i <= 45)
		{
			getline(pak, TTname[k]);
			if (k == 0)
			{
				captan = TTname[k];
			}
			if (k == 1)
			{
				wicketkeeper = TTname[k];
			}
			if (k == 15)
			{
				coach = TTname[k];
				TTname[k] = ' ';
			}
			k++;
			i++;
		}

	}
	pak.close();
	system("cls");
	displayTeam();
	cout << "enter the name of player you want to remove" << endl;
	getline(cin >> ws, str);
	int l = 0;
	for (int i = 0; i < size; i++)
	{
		if (str == Tname[i])
		{
			int temp = i;
			if (temp == size - 1)
			{
				Tname[i] = " ";
				cout << " team after removal of player" << endl;
				displayTeam();
				system("cls");
				break;
			}
			
			for (int i = temp; i < size-1; i++)
			{
				
				
					Tname[i] = Tname[i + 1];
				
			}
			cout << " team after removal of player" << endl;
			displayTeam();
			system("cls");
			break;
		}
		if (str == Oname[i] )
		{
			int temp = i;
			for (int i = temp; i < size - 1; i++)
			{
				Oname[i] = Oname[i + 1];
			}
			cout << " team after removal of player" << endl;
			displayTeam();
			system("cls");
			break;
		}
		if (str == TTname[i])
		{
			int temp = i;
			for (int i = temp; i < size - 1; i++)
			{
				TTname[i] = TTname[i + 1];
			}
			cout << " team after removal of player" << endl;
			displayTeam();
			system("cls");
			break;
		}
		l++;
	}
	
	
	if (l == 0)
	{
		cout << " player not found in squad " << endl;
		system("pause");
	}
}
void Team::searchPlayer()
{
	int x = 0;
	string name;
	cout << " enter the name of the player you want to search " << endl;
	getline(cin >> ws, name);
	for (int i = 0; i < size; i++)
	{
		if (name == Tname[i])
		{
			cout << Tname[i] << " found is test squad of " << teamName << endl;
			x++;
			break;
		}
		if (name == Oname[i])
		{
			cout << Oname[i] << " found is test squad of " << teamName << endl;
			x++;
			break;
		}
		if (name == TTname[i])
		{
			cout << TTname[i] << " found is test squad of " << teamName << endl;
			x++;
			break;
		}
	}
	if (x == 0)
	{
		cout << " player not found " << endl;
	}
	system("pause");
	

}
void Team::updatePlayer()
{
	float f;
	fstream pak;
	pak.open("stats.txt");
	int a = 0;
	while (!pak.eof())
	{
		pak >> f;
		shirtNumber[a] = f;
		pak >> f;
		average[a] = f;
		pak >> f;
		rankingT20[a] = f;
		pak >> f;
		rankingODI[a] = f;
		pak >> f;
		rankingTest[a] = f;
		pak >> f;
		totalRuns[a] = f;
		pak >> f;
		matchesPlayed[a] = f;
		pak >> f;
		totalWickets[a] = f;
		a++;
	}
	pak.close();
	int choice;
	string name;
	cout << " which team player you want to update " << endl;
	cout << "1:Pakistan" << endl;
	cout << "2:India" << endl;
	cout << "3:England" << endl;
	cout << "4:Austrailia" << endl;
	cout << "5:South Africa" << endl;
	cout << "6:New Zeland" << endl;
	cin >> choice;
	if (choice == 1)
	{
		teamName = "PAKISTAN";
		pak.open("pak.txt");
	}
	if (choice == 2)
	{
		teamName = "INDIA";
		pak.open("india.txt");
	}
	if (choice == 3)
	{
		teamName = "ENGLAD";
		pak.open("eng.txt");
	}
	if (choice == 4)
	{
		teamName = "AUSTRALIA";
		pak.open("aus.txt");
	}
	if (choice == 5)
	{
		teamName = "SouthAfrca";
		pak.open("sa.txt");
	}
	if (choice == 6)
	{
		teamName = "NewZeland";
		pak.open("nz.txt");
	}
	int i = 0, j = 0, k = 0;
	while (!pak.eof())
	{
		if (i >= 0 && i < 15)
		{
			getline(pak, Tname[i]);
			if (i == 0)
			{
				captan = Tname[i];
			}
			if (i == 1)
			{
				wicketkeeper = Tname[i];
			}
			i++;
		}
		if (i >= 15 && i < 30)
		{
			getline(pak, Oname[j]);
			if (j == 0)
			{
				captan = Oname[j];
			}
			if (j == 1)
			{
				wicketkeeper = Oname[j];
			}
			j++;
			i++;
		}
		if (i >= 30 && i <= 45)
		{
			getline(pak, TTname[k]);
			if (k == 0)
			{
				captan = TTname[k];
			}
			if (k == 1)
			{
				wicketkeeper = TTname[k];
			}
			if (k == 15)
			{
				coach = TTname[k];
				TTname[k] = ' ';
			}
			k++;
			i++;
		}

	}
	pak.close();
	system("cls");
	displayTeam();
	cout << " enter the name of the player you want to updtae data " << endl;
	getline(cin >> ws, name);
	for (int i = 0; i < size; i++)
	{
		int option;
		if (name == Tname[i])
		{
			cout << " current stats of " << name << endl;
			cout << " T20 Ranking " << rankingT20[i] << endl;
			cout << " ODI Ranking " << rankingODI[i] << endl;
			cout << " Test Ranking " << rankingTest[i] << endl;
			cout << " Shirt number " << shirtNumber[i] << endl;
			cout << " Average " << average[i] << endl;
			cout << " Total Runs " << totalRuns[i] << endl;
			cout << " Matches palyed " << matchesPlayed[i] << endl;
			cout << " Total Wickets " << totalWickets[i] << endl;
			system("pause");
			system("cls");
			cout << " which stat you want to update " << endl;
			cout << " 1:T20 Ranking " << endl;
			cout << " 2:ODI Ranking "  << endl;
			cout << " 3:Test Ranking "  << endl;
			cout << " 4:Shirt number "  << endl;
			cout << " 5:Average " << endl;
			cout << " 6:Total Runs "  << endl;
			cout << " 7:Matches palyed "  << endl;
			cout << " 8:Total Wickets "  << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				int a;
				cout << " enter new T20 Ranking of " << name << endl;
				cin >> a;
				rankingT20[i] = a;
				break;
			case 2:
				cout << " enter new ODI Ranking of " << name << endl;
				cin >> a;
				rankingODI[i] = a;
				break;
			case 3:
				cout << " enter new Test Ranking of " << name << endl;
				cin >> a;
				rankingTest[i] = a;
				break;
			case 4:
				cout << " enter new Shirt number of " << name << endl;
				cin >> a;
				shirtNumber[i] = a;
				break;
			case 5:
				cout << " enter new Verage of " << name << endl;
				cin >> a;
				average[i] = a;
				break;
			case 6:
				cout << " enter new Total runs of " << name << endl;
				cin >> a;
				totalRuns[i] = a;
				break;
			case 7:
				cout << " enter new number  of matches played of " << name << endl;
				cin >> a;
				matchesPlayed[i] = a;
				break;
			case 8:
				cout << " enter new Total wickets of " << name << endl;
				cin >> a;
				totalWickets[i] = a;
				break;
			default:
				cout << " wrong input enter again " << endl;
			}
			cout << " New stats of " << name << endl;
			cout << " T20 Ranking " << rankingT20[i] << endl;
			cout << " ODI Ranking " << rankingODI[i] << endl;
			cout << " Test Ranking " << rankingTest[i] << endl;
			cout << " Shirt number " << shirtNumber[i] << endl;
			cout << " Average " << average[i] << endl;
			cout << " Total Runs " << totalRuns[i] << endl;
			cout << " Matches palyed " << matchesPlayed[i] << endl;
			cout << " Total Wickets " << totalWickets[i] << endl;
			cout << endl;

		}
	}
}
void Team::displayMatches()
{
	fstream match;
	int choice;
	string matches;
	cout << " which matches you want to see " << endl;
	cout << " 1:Upcoming Matches " << endl;
	cout << " 2:previous matches " << endl;
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		match.open("matches.txt");
		while (!match.eof())
		{
			getline(match, matches);
			cout << matches << endl;
		}
		match.close();
		break;
	case 2:
		int choice=0,n=0;
		while (choice!=6)
		{
			cout << " select any match you want to see details of " << endl;
			match.open("Pmatch.txt");
			while (!match.eof())
			{
				getline(match, matches);
				cout << matches << endl;
			}
			match.close();
			cout << "6:Go back" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				cout << "TOSS: India won the toss and choose to bowl " << endl;
				cout << "					Summary " << endl;
				cout << "				Pakistan 159/8		" << endl;
				cout << " Shan Masood 52* (42)					Hardik Pandya 3/30 (4)" << endl;
				cout << " Iftikhar Ahmad 51 (34)				Arshadeep Singh 3/32 (4)" << endl;
				cout << "				India 160/6" << endl;
				cout << " Virat kohli 82* (53)					Haris Rauf 2/36 (4)" << endl;
				cout << " Hardik Pandya 40 (37)					Muhammad Nawaz 2/42 (4)" << endl;
				cout << " Player of the Match: Virat Kohli " << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout << "TOSS: Austrailia won the toss and choose to bowl " << endl;
				cout << "					Summary " << endl;
				cout << "				NewZeland 200/3		" << endl;
				cout << " Dewon Conway 92* (58)					Josh Hazlewood 2/41 (4)" << endl;
				cout << " Finn Allen 42 (16)					Adam Zampa 1/39 (4)" << endl;
				cout << "				Australia 111/10" << endl;
				cout << " Glenn Maxwell 28 (20)					Tim Southee 3/6 (2.1)" << endl;
				cout << " Pat Cummins 21 (18)					Mitchell Santner 3/31 (4)" << endl;
				cout << " Player of the Match: Dewon Conway " << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				cout << "TOSS: NewZeland won the toss and choose to bat " << endl;
				cout << "					Summary " << endl;
				cout << "				NewZeland 152/4		" << endl;
				cout << " Darryl mitchell 53* (35)				shaheen Afridi 2/24 (4)" << endl;
				cout << " Kane williamson 46 (42)				muhammad Nawaz 1/12 (4)" << endl;
				cout << "				Pakistan 153/3" << endl;
				cout << " Muhammad Rizwan 57 (43)				Trent Boult 2/33 (4)" << endl;
				cout << " Babar Azam 53 (42)					Mitchell Santner 1/26 (4)" << endl;
				cout << " Player of the Match: Muhammad Rizwan " << endl;
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				cout << "TOSS: England won the toss and choose to bowl " << endl;
				cout << "					Summary " << endl;
				cout << "				India 168/6		" << endl;
				cout << " Hardik Pandya 63* (33)				Chris Jordan 3/43 (4)" << endl;
				cout << " Virat Kohli 50 (40)					Adil Rashid 1/20 (4)" << endl;
				cout << "				Pakistan 153/3" << endl;
				cout << " Alex Hales 86* (47)					Arshadeep Singh 0/15 (2)" << endl;
				cout << " Jos buttler 80 (49)					Ravi Chandran Ashwin 0/27 (2)" << endl;
				cout << " Player of the Match: Alex Hales " << endl;
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				cout << "TOSS: England won the toss and choose to bowl " << endl;
				cout << "					Summary " << endl;
				cout << "				Pakistan 137/8" << endl;
				cout << " Shan Masood 38 (28)					Sam Cuarran 2/12 (4)" << endl;
				cout << " Babar Azam 32 (28)					Adil Rashid 2/22 (4)" << endl;
				cout << " Player of the Match: Muhammad Rizwan " << endl;
				cout << "				England 152/4		" << endl;
				cout << " Ben Stokes 52* (49)					HAris Rauf 2/23	 (4)" << endl;
				cout << " Jos Buttler 26 (17)					shaheen Afridi 1/13 (2.1)" << endl;
				cout << " Player of the Match: Sam Curran " << endl;
				system("pause");
				system("cls");
				break;
			case 6:
				break;
			}
		}
	}

}
void Team::updateCaptain()
{
	string name;
	cout << " current caption of " << teamName << " is " << captan << endl;
	cout << " enter the player name you want to make captan" << endl;
	getline(cin >> ws, name);
	captan = name;
	system("cls");
	cout << " squad after updating captan" << endl;
	displayTeam();
}
void Team::updateCoach()
{
	string name;
	cout << " current Coach of " << teamName << " is " << coach << endl;
	cout << " enter the player name you want to make captan" << endl;
	getline(cin >> ws, name);
	coach = name;
	system("cls");
	cout << " squad after updating Coach" << endl;
	displayTeam();
}
void Team::displayTeam()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		
		//system("cls");
		int len;
		len = 40 - (14 + teamName.length());
		SetConsoleTextAttribute(color, 4); cout << "-------------------------------------------------------------------------------------------------------" << endl;
		SetConsoleTextAttribute(color, 4); cout << "|"; SetConsoleTextAttribute(color, 10); cout << "TEST squad of  "<<teamName << setw(len); SetConsoleTextAttribute(color, 4); cout << "|"; SetConsoleTextAttribute(color, 10); cout << "ODI squad of " << teamName << setw(len); SetConsoleTextAttribute(color, 4); cout << "|"; SetConsoleTextAttribute(color, 10); cout << "T20 squaf of " << teamName; SetConsoleTextAttribute(color, 4); cout << "| " << endl; SetConsoleTextAttribute(color, 9);
		SetConsoleTextAttribute(color, 4); cout << "-------------------------------------------------------------------------------------------------------" << endl;
		int len1, len2, len3;
		for (int i = 0; i < size; i++)
		{
			len1 = 40 - Tname[i].length();
			//cout << len1 << ' ';
			len2 = 40 - Oname[i].length();
			len3 = 22 - TTname[i].length();	
			SetConsoleTextAttribute(color, 4); cout << "|"; SetConsoleTextAttribute(color, 9); cout << Tname[i] << setw(len1); SetConsoleTextAttribute(color, 4); cout << "|"; SetConsoleTextAttribute(color, 9); cout << Oname[i] << setw(len2); SetConsoleTextAttribute(color, 4); cout << "|"; SetConsoleTextAttribute(color, 9); cout << TTname[i] << setw(len3); SetConsoleTextAttribute(color, 4); cout << "|" << endl;
		}
		SetConsoleTextAttribute(color, 4); cout << "-------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		SetConsoleTextAttribute(color, 9); cout << " Captain: " << captan << "		";
		cout << " Wicket keeper: " << wicketkeeper << "		";
		cout << " Coach: " << coach << endl;
		system("pause");
}


 
//Match.h:
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


//Match.cpp:
# include "Match.h"
#include<fstream>
# include <string>
Match::Match()
{
	this->Commentators = " ";
	this->sdate = 0;
	this->edate = 0;
	this->matchstatus = " ";
	this->matchType = " ";
	this->Team1 = " ";
	this->Team2 = " ";
	this->tournamentName = " ";
	this->umpires = " ";
	this->venue = " ";
	*Teams=" ";
	*venues = " ";
}

void Match::conductMatch()
{
	int option=0;
	fstream pak;
	string match;
	while (option != 3)
	{
		cout << " You want to coduct which Type of match " << endl;
		cout << " 1:Already sheduled match" << endl;
		cout << " 2:Shedule a new match" << endl;
		cout << " 3:Main menu" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			int option;
			system("cls");
			cout << " Select any one of the sheduled match you want to conduct " << endl;
			pak.open("matches.txt");
			for (int i = 0; i < 3; i++)
			{
				getline(pak, match);
				cout << match << endl;
			}
			pak.close();
			cin >> option;
			switch (option)
			{
			case 1:
				system("cls");
				cout << "		Austrailia vs SouthAfrica 2 match Test series " << endl << endl;
				cout << "			Result after the first match " << endl << endl;
				cout << "			Austrailia first innings " << endl;
				cout << "				469/10" << endl;
				cout << " Steve Smith 123(257)			Lungi Ngidi 3/186" << endl;
				cout << "			South Africa first innings " << endl;
				cout << "				275/10" << endl;
				cout << " Dean Algar 98(175)			Mitchel Starc 4/43" << endl;
				cout << "			 Austrailia second innings " << endl;
				cout << "				257/3 D" << endl;
				cout << " Steve Smith 85(164)			Lungi Ngidi 2/126" << endl;
				cout << "			South Africa first innings " << endl;
				cout << "				351/10" << endl;
				cout << " Dean Algar 126(175)			Mitchel Starc 5/75" << endl;
				cout << "		Ausrailia won the match by 36 runs " << endl;

				cout << "			Result after the second match " << endl << endl;
				cout << "			Austrailia first innings " << endl;
				cout << "				329/10" << endl;
				cout << " Mathew Wade 142(257)			Lungi Ngidi 3/186" << endl;
				cout << "			South Africa first innings " << endl;
				cout << "				428/10" << endl;
				cout << " Dean Algar 158(175)			Mitchel Starc 4/43" << endl;
				cout << "			 Austrailia second innings " << endl;
				cout << "				263/10 " << endl;
				cout << " Steve Smith 85(192)			Lungi Ngidi 2/126" << endl;
				cout << "			South Africa second innings " << endl;
				cout << "				166/5" << endl;
				cout << " Dean Algar 58(105)			Mitchel Starc 1/25" << endl;
				cout << "		South Africa won the match by 5 wickets " << endl << endl;
				cout << "			Series drawn 1-1" << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout << "		Pakistan vs Newzeland 2 match Test seies " << endl << endl;
				cout << "			Result after the first match " << endl << endl;
				cout << "			NewZeland first innings " << endl;
				cout << "				374/10" << endl;
				cout << " Kane williamson 145(257)			Abrar Ahmad 5/127" << endl;
				cout << "			Pakistan first innings " << endl;
				cout << "				380/10" << endl;
				cout << " Babar Azam 173(265)				Tim Southee 4/43" << endl;
				cout << "			 NewZeland second innings " << endl;
				cout << "				305/3 D" << endl;
				cout << " Kane Williamson 93(164)			Trent Boult 2/126" << endl;
				cout << "			South Africa first innings " << endl;
				cout << "				300/7" << endl;
				cout << " Imam ul Haq 119(175)			Tim Southee 5/175" << endl;
				cout << "		Pakistan won the match by 3 wickets " << endl;

				cout << "			Result after the second match " << endl << endl;
				cout << "			NewZeland first innings " << endl;
				cout << "				284/10" << endl;
				cout << " Kane williamson 55(117)			Abrar Ahmad 5/127" << endl;
				cout << "			Pakistan first innings " << endl;
				cout << "				384/10" << endl;
				cout << " Babar Azam 182(365)				Tim Southee 4/43" << endl;
				cout << "			 NewZeland second innings " << endl;
				cout << "				300/10 " << endl;
				cout << " Kane Williamson 93(164)			Trent Boult 2/126" << endl;
				cout << "			South Africa first innings " << endl;
				cout << "				200/4" << endl;
				cout << " Babar Azam 119(175)			Tim Southee 2/75" << endl;
				cout << "		Pakistan won the match by 6 wickets " << endl;
				cout << "			Series Won by Pakistan 2-0" << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				cout << "		India vs Srilanka 2 match T20 seies " << endl << endl;
				cout << "			Result after the first match " << endl << endl;
				cout << "			India  " << endl;
				cout << "				193/5" << endl;
				cout << " Virat kohli 73(46)*				Hassaranga 2/27" << endl;
				cout << "			Srilanka " << endl;
				cout << "				153/10" << endl;
				cout << " Kuasal Mendis 52(39)				Jasprit Bumrah 3/23" << endl;
				cout << "		India won the match by 40 runs " << endl << endl;
				cout << "			Result after the first match " << endl << endl;
				cout << "			Srilanka" << endl;
				cout << "				175/3 D" << endl;
				cout << " Thisara Parera 93(47)			Ashwin 2/36" << endl;
				cout << "			India " << endl;
				cout << "				170/7" << endl;
				cout << " Rohit Sharma 48(40)			Hassaranga 5/15" << endl;
				cout << "		Srilanka won the match by 5 runs " << endl;
				cout << "			Series Drawn 1-1" << endl;
				system("pause");
				system("cls");
				break;
			}
			break;
			case 2:
				scheduleMatch();
				break;
			case 3:
				break;
		}
	}
}
void Match::scheduleMatch()
{
	int num;
	cout << " Enter name of any 2 teams " << endl;
	cout << "1:Pakistan" << endl;
	cout << "2:India" << endl;
	cout << "3:England" << endl;
	cout << "4:Austrailia" << endl;
	cout << "5:South Africa" << endl;
	cout << "6:New Zeland" << endl;
	cin >> Team1;
	cin >> Team2;
	cout << " Eneter the venue of match " << endl;
	cin >> venue;
	cout << " Enter match Type ODI,T20 etc.." << endl;
	cin >> matchType;
	system("cls");
	cout << " Result of " << matchType << " match between " << Team1 << " and " << Team2 << endl;
	num = (rand() % 2) + 1;
	if (num == 1)
	{
		cout << Team1 << " won the match " << endl;
	}
	else
	{
		cout << Team2 << " won the match " << endl;
	}
	system("pause");

}
void Match::conductTournament()
{
	int size;
	int count=0;
	string option;
	string str;
	fstream file;
	cout << " Enter the name of tournament you want to conduct " << endl;
	getline(cin >> ws, tournamentName);
	cout << " select more than 2 teams to conduct tournament " << endl;
	cout << "Pakistan" << endl;
	cout << "India" << endl;
	cout << "England" << endl;
	cout << "Austrailia" << endl;
	cout << "South Africa" << endl;
	cout << "New Zeland" << endl;
	cout << " enter the number of teams you want to pick for tournament " << endl;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << " eneter the name of team " << i + 1 << endl;
		cin >> Teams[i];
	}
	cout << " select any 3 venues for " << tournamentName << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " enter venue " << i + 1 << " for " << tournamentName << endl;
		getline(cin >> ws, venues[i]);
	}
	cout << " eneter starting date of " << tournamentName << endl;
	cin >> sdate;
	cout << " eneter the ending date of tournament " << endl;
	cin >> edate;
	system("cls");
	cout << " Shedule of " << tournamentName << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			cout << Teams[i] << " vs " << Teams[j] << endl;
			count++;
		}
	}
	cout << "Final" << endl;
	file.open("tournament.txt");
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			file << Teams[i] << endl;
		}
	}
	file.close();
	system("pause");
	system("cls");
	file.open("tournament.txt");
	for (int i = 0; i < count; i++)
	{
		cout << " press  any key to see the result of match " << i + 1;
		cin >> option;
		file >> str;
		cout << str << " win the match " << endl;	
	}
	cout << " press any key to see result of Final " << endl;
	cin >> option;
	cout << Teams[0] << " wins the match " << endl << endl;
	cout << Teams[0] << " wins the " << tournamentName << " comprehensively" << endl;
	cout << " press any key to see the stats of this " << tournamentName << endl;
	cin >> option;
	system("cls");
	updateWorldRecords();
}
void Match::updateWorldRecords()
{
	if (Teams[0] == "Pakistan")
	{
		cout << " Most runs in this " << tournamentName << ": Babar Azam " << endl;
		cout << " Highest score in this " << tournamentName << ": Babar Azam " << endl;
		cout << " Most sixes in this " << tournamentName << ": Asif Ali " << endl;
		cout << " Most fours in this " << tournamentName << ": Babar Azam " << endl;
		cout << " Most centuries in this " << tournamentName << ": Babar Azam " << endl;
		cout << " Highest batting average in this " << tournamentName << ": Babar Azam " << endl;
		cout << " Best batting strike rate in this " << tournamentName << ": Asif Ali " << endl;
		cout << " Most wickets in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling avg in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling in this " << tournamentName << ": Haris Rauf " << endl;
	}
	if (Teams[0] == "India")
	{
		cout << " Most runs in this " << tournamentName << ": Virat Kohli " << endl;
		cout << " Highest score in this " << tournamentName << ": Virat Kohli " << endl;
		cout << " Most sixes in this " << tournamentName << ": Suriya Kumar Yadav " << endl;
		cout << " Most fours in this " << tournamentName << ": Virat Kohli " << endl;
		cout << " Most centuries in this " << tournamentName << ": Virat Kohli " << endl;
		cout << " Highest batting average in this " << tournamentName << ": Virat Kohli " << endl;
		cout << " Best batting strike rate in this " << tournamentName << ": Suriya Kumar Yadav " << endl;
		cout << " Most wickets in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling avg in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling in this " << tournamentName << ": Haris Rauf " << endl;
	}
	if (Teams[0] == "England")
	{
		cout << " Most runs in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Highest score in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Most sixes in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Most fours in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Most centuries in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Highest batting average in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Best batting strike rate in this " << tournamentName << ": Jos Buttler " << endl;
		cout << " Most wickets in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling avg in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling in this " << tournamentName << ": Haris Rauf " << endl;
	}
	if (Teams[0] == "Austrailia")
	{
		cout << " Most runs in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Highest score in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Most sixes in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Most fours in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Most centuries in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Highest batting average in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Best batting strike rate in this " << tournamentName << ": Mathew Wade " << endl;
		cout << " Most wickets in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling avg in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling in this " << tournamentName << ": Haris Rauf " << endl;
	}
	if (Teams[0] == "SouthAfrica")
	{
		cout << " Most runs in this " << tournamentName << ": David Miller " << endl;
		cout << " Highest score in this " << tournamentName << ": David Miller " << endl;
		cout << " Most sixes in this " << tournamentName << ": David Miller " << endl;
		cout << " Most fours in this " << tournamentName << ": David Miller " << endl;
		cout << " Most centuries in this " << tournamentName << ": David Miller " << endl;
		cout << " Highest batting average in this " << tournamentName << ": David Miller " << endl;
		cout << " Best batting strike rate in this " << tournamentName << ": David Miller " << endl;
		cout << " Most wickets in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling avg in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling in this " << tournamentName << ": Haris Rauf " << endl;
	}
	if (Teams[0] == "NewZeland")
	{
		cout << " Most runs in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Highest score in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Most sixes in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Most fours in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Most centuries in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Highest batting average in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Best batting strike rate in this " << tournamentName << ": Martin Guptil " << endl;
		cout << " Most wickets in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling avg in this " << tournamentName << ": Shaheen Shah Afridi " << endl;
		cout << " Best bowling in this " << tournamentName << ": Haris Rauf " << endl;
	}
}
void Match::displayUpcomingMatches()
{
	fstream match;
	string matches;
	cout << " some of the upcomming matches " << endl;
	match.open("matches.txt");
	while (!match.eof())
	{
		getline(match, matches);
		cout << matches << endl;
	}
	match.close();
}
void Match::displayRecentMatches()
{
	fstream match;
	int choice = 0;
	string matches;
	while (choice != 6)
	{
		cout << " select any match you want to see details of " << endl;
		match.open("Pmatch.txt");
		while (!match.eof())
		{
			getline(match, matches);
			cout << matches << endl;
		}
		match.close();
		cout << "6:Go back" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "TOSS: India won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				Pakistan 159/8		" << endl;
			cout << " Shan Masood 52* (42)					Hardik Pandya 3/30 (4)" << endl;
			cout << " Iftikhar Ahmad 51 (34)				Arshadeep Singh 3/32 (4)" << endl;
			cout << "				India 160/6" << endl;
			cout << " Virat kohli 82* (53)					Haris Rauf 2/36 (4)" << endl;
			cout << " Hardik Pandya 40 (37)					Muhammad Nawaz 2/42 (4)" << endl;
			cout << " Player of the Match: Virat Kohli " << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "TOSS: Austrailia won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				NewZeland 200/3		" << endl;
			cout << " Dewon Conway 92* (58)					Josh Hazlewood 2/41 (4)" << endl;
			cout << " Finn Allen 42 (16)					Adam Zampa 1/39 (4)" << endl;
			cout << "				Australia 111/10" << endl;
			cout << " Glenn Maxwell 28 (20)					Tim Southee 3/6 (2.1)" << endl;
			cout << " Pat Cummins 21 (18)					Mitchell Santner 3/31 (4)" << endl;
			cout << " Player of the Match: Dewon Conway " << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "TOSS: NewZeland won the toss and choose to bat " << endl;
			cout << "					Summary " << endl;
			cout << "				NewZeland 152/4		" << endl;
			cout << " Darryl mitchell 53* (35)				shaheen Afridi 2/24 (4)" << endl;
			cout << " Kane williamson 46 (42)				muhammad Nawaz 1/12 (4)" << endl;
			cout << "				Pakistan 153/3" << endl;
			cout << " Muhammad Rizwan 57 (43)				Trent Boult 2/33 (4)" << endl;
			cout << " Babar Azam 53 (42)					Mitchell Santner 1/26 (4)" << endl;
			cout << " Player of the Match: Muhammad Rizwan " << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "TOSS: England won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				India 168/6		" << endl;
			cout << " Hardik Pandya 63* (33)				Chris Jordan 3/43 (4)" << endl;
			cout << " Virat Kohli 50 (40)					Adil Rashid 1/20 (4)" << endl;
			cout << "				Pakistan 153/3" << endl;
			cout << " Alex Hales 86* (47)					Arshadeep Singh 0/15 (2)" << endl;
			cout << " Jos buttler 80 (49)					Ravi Chandran Ashwin 0/27 (2)" << endl;
			cout << " Player of the Match: Alex Hales " << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "TOSS: England won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				Pakistan 137/8" << endl;
			cout << " Shan Masood 38 (28)					Sam Cuarran 2/12 (4)" << endl;
			cout << " Babar Azam 32 (28)					Adil Rashid 2/22 (4)" << endl;
			cout << " Player of the Match: Muhammad Rizwan " << endl;
			cout << "				England 152/4		" << endl;
			cout << " Ben Stokes 52* (49)					HAris Rauf 2/23	 (4)" << endl;
			cout << " Jos Buttler 26 (17)					shaheen Afridi 1/13 (2.1)" << endl;
			cout << " Player of the Match: Sam Curran " << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
 



//News.h:
# include<iostream>
using namespace std;
class News
{
public:
	News();
	void previousMatches();
	void upcoming();
	void Rankings();
};
News.cpp:
# include "News.h"
#include<fstream>
# include <string>
News::News()
{

}
void News::previousMatches()
{
	fstream match;
	int choice = 0;
	string matches;
	while (choice != 6)
	{
		cout << " select any match you want to see details of " << endl;
		match.open("Pmatch.txt");
		while (!match.eof())
		{
			getline(match, matches);
			cout << matches << endl;
		}
		match.close();
		cout << "6:Go back" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "TOSS: India won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				Pakistan 159/8		" << endl;
			cout << " Shan Masood 52* (42)					Hardik Pandya 3/30 (4)" << endl;
			cout << " Iftikhar Ahmad 51 (34)				Arshadeep Singh 3/32 (4)" << endl;
			cout << "				India 160/6" << endl;
			cout << " Virat kohli 82* (53)					Haris Rauf 2/36 (4)" << endl;
			cout << " Hardik Pandya 40 (37)					Muhammad Nawaz 2/42 (4)" << endl;
			cout << " Player of the Match: Virat Kohli " << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "TOSS: Austrailia won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				NewZeland 200/3		" << endl;
			cout << " Dewon Conway 92* (58)					Josh Hazlewood 2/41 (4)" << endl;
			cout << " Finn Allen 42 (16)					Adam Zampa 1/39 (4)" << endl;
			cout << "				Australia 111/10" << endl;
			cout << " Glenn Maxwell 28 (20)					Tim Southee 3/6 (2.1)" << endl;
			cout << " Pat Cummins 21 (18)					Mitchell Santner 3/31 (4)" << endl;
			cout << " Player of the Match: Dewon Conway " << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "TOSS: NewZeland won the toss and choose to bat " << endl;
			cout << "					Summary " << endl;
			cout << "				NewZeland 152/4		" << endl;
			cout << " Darryl mitchell 53* (35)				shaheen Afridi 2/24 (4)" << endl;
			cout << " Kane williamson 46 (42)				muhammad Nawaz 1/12 (4)" << endl;
			cout << "				Pakistan 153/3" << endl;
			cout << " Muhammad Rizwan 57 (43)				Trent Boult 2/33 (4)" << endl;
			cout << " Babar Azam 53 (42)					Mitchell Santner 1/26 (4)" << endl;
			cout << " Player of the Match: Muhammad Rizwan " << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "TOSS: England won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				India 168/6		" << endl;
			cout << " Hardik Pandya 63* (33)				Chris Jordan 3/43 (4)" << endl;
			cout << " Virat Kohli 50 (40)					Adil Rashid 1/20 (4)" << endl;
			cout << "				Pakistan 153/3" << endl;
			cout << " Alex Hales 86* (47)					Arshadeep Singh 0/15 (2)" << endl;
			cout << " Jos buttler 80 (49)					Ravi Chandran Ashwin 0/27 (2)" << endl;
			cout << " Player of the Match: Alex Hales " << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "TOSS: England won the toss and choose to bowl " << endl;
			cout << "					Summary " << endl;
			cout << "				Pakistan 137/8" << endl;
			cout << " Shan Masood 38 (28)					Sam Cuarran 2/12 (4)" << endl;
			cout << " Babar Azam 32 (28)					Adil Rashid 2/22 (4)" << endl;
			cout << " Player of the Match: Muhammad Rizwan " << endl;
			cout << "				England 152/4		" << endl;
			cout << " Ben Stokes 52* (49)					HAris Rauf 2/23	 (4)" << endl;
			cout << " Jos Buttler 26 (17)					shaheen Afridi 1/13 (2.1)" << endl;
			cout << " Player of the Match: Sam Curran " << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
void News::upcoming()
{
	fstream match;
	string matches;
	cout << " some of the upcomming matches " << endl;
	match.open("matches.txt");
	while (!match.eof())
	{
		getline(match, matches);
		cout << matches << endl;
	}
	match.close();
}
void News::Rankings()
{
	int option=0;
	while (option != 3)
	{
		cout << " which rankings you want to see " << endl;
		cout << " 1:Palyers" << endl;
		cout << " 2:Teams" << endl;
		cout << " 3:Main menu" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			while (option != 4)
			{
				cout << " which format ranking you to see " << endl;
				cout << "1:T20" << endl;
				cout << "2:ODI" << endl;
				cout << "3:Test" << endl;
				cout << "4:Go back" << endl;
				cin >> option;
				switch (option)
				{
				case 1:
					cout << " Player			Rankings" << endl << endl;
					cout << " Babar Azam				1" << endl;
					cout << " Muhammad Rizwan				2" << endl;
					cout << " Dawid Malan				3" << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					cout << " Player			Rankings" << endl;
					cout << " Babar Azam			1" << endl;
					cout << " Imam ul Haq			2" << endl;
					cout << " Russie wonderdussen		3" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					cout << " Player			Rankings" << endl;
					cout << " Joe Root					1" << endl;
					cout << " Marnus				2" << endl;
					cout << " Babar Azam			3" << endl;
					system("pause");
					system("cls");
					break;
				case 4:
					break;
				}
			}
			break;
		case 2:
			while (option != 4)
			{
				cout << " which format ranking you to see " << endl;
				cout << "1:T20" << endl;
				cout << "2:ODI" << endl;
				cout << "3:Test" << endl;
				cin >> option;
				switch (option)
				{
				case 1:
					cout << " Team					Rankings" << endl;
					cout << " India						1" << endl;
					cout << " Pakistan					2" << endl;
					cout << " Austrailia					3" << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					cout << " Team					Rankings" << endl;
					cout << " India						1" << endl;
					cout << " South Africa					2" << endl;
					cout << " Austrailia					3" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					cout << " Team					Rankings" << endl;
					cout << " India						1" << endl;
					cout << " England					2" << endl;
					cout << " Austrailia					3" << endl;
					system("pause");
					system("cls");
					break;
				case 4:
					break;
				}
			}
			break;

		}
	}
}
