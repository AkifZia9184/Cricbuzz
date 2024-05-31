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