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