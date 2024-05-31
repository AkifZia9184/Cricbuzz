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
				cout << "4:Goback" << endl;
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