# include"Match.h"
#include"player.h"
# include"Team.h"
# include"News.h"
# include<fstream>
#include<string>
# include<Windows.h>
int main()
{
	string hello;
	string email;
	string temp;
	string password;
	Player* p;
	Team t;
	p = &t;
	Match m;
	News n;
	int choice=0;
	char option='a';
	fstream pak;
	int x = 0;
	pak.open("login.txt");
	getline(pak, email);
	getline(pak, password);
	pak.close();
	cout << endl << endl << endl<<endl<<endl;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 2);
	cout << "		                   ***  ***    *   ***  *     *   *  ****  ****" << endl;
	cout << "		                  *     *   *  *  *     ***   *   *    *     *" << endl;
	cout << "		                  *     * *    *  *     *  *  *   *  *     *" << endl;
	cout << "		                   ***  *  *   *   ***  ***    ***   ****  ****" << endl;
	SetConsoleTextAttribute(color, 9);

	while (email != " ")
	{
		cout << " Enter the user name or Email to login " << endl;
		getline(cin >> ws, temp);
	
		if (temp == email)
		{
			string pass;
			cout << " Enter your Password " << endl;
			getline(cin >> ws, pass);
			while (pass != " ")
			{
				if (pass == password)
				{
					x++;
					break;
				}
				else
				{
					cout << " wrong password enter password again " << endl;
					system("pause");
					system("cls");
				}
			}
			if (x == 1)
			{
				system("cls");
				break;
			}
		}
		else
		{
			cout << " wrong Email enter password again " << endl;
			system("pause");
			system("cls");
		}
	}
	while (option!='E')
	{
		cout << "				WELCOME		TO	CRICBUZZ " << endl<<endl;
		cout << "				select the facility you want to use " << endl;
		cout << "				1:Display Team" << endl;
		cout << "				2:Add player to the team" << endl;
		cout << "				3:Remove player from the team " << endl;
		cout << "				4:Search player " << endl;
		cout << "				5:Update player" << endl;
		cout << "				6:Update captian" << endl;
		cout << "				7:Update coach" << endl;
		cout << "				8:Display matches" << endl;
		cout << "				9:View stats " << endl;
		cout << "				10:Conduct match" << endl;
		cout << "				11:Conduct Tornament " << endl;
		cout << "				12:Display upcomming matches " << endl;
		cout << "				13:Display recent matches " << endl;
		cout << "				14:View Rankings" << endl;
		cout << "				15:exit" << endl;
		cout << endl;
		cin >> choice;
		system("cls");
		int i = 0, j = 0, k = 0;
		switch (choice)
		{
		case 1:
			
			cout << " which team you want to see " << endl;
			cout << "1:Pakistan" << endl;
			cout << "2:India" << endl;
			cout << "3:England" << endl;
			cout << "4:Austrailia" << endl;
			cout << "5:South Africa" << endl;
			cout << "6:New Zeland" << endl;
			cin >> choice;
			if (choice == 1)
			{
				t.teamName = "PAKISTAN";
				pak.open("pak.txt");
			}
			if (choice == 2)
			{
				t.teamName = "INDIA";
				pak.open("india.txt");
			}
			if (choice == 3)
			{
				t.teamName = "ENGLAD";
				pak.open("eng.txt");
			}
			if (choice == 4)
			{
				t.teamName = "AUSTRALIA";
				pak.open("aus.txt");
			}
			if (choice == 5)
			{
				t.teamName = "SouthAfrca";
				pak.open("sa.txt");
			}
			if (choice == 6)
			{
				t.teamName = "NewZeland";
				pak.open("nz.txt");
			}
			
			while (!pak.eof())
			{
				if (i >= 0 && i < 15)
				{
					getline(pak, t.Tname[i]);
					if (i == 0)
					{
						t.captan = t.Tname[i];
					}
					if (i == 1)
					{
						t.wicketkeeper = t.Tname[i];
					}
					i++;
				}
				if (i >= 15 && i < 30)
				{
					getline(pak, t.Oname[j]);
					if (j == 0)
					{
						t.captan = t.Oname[j];
					}
					if (j == 1)
					{
						t.wicketkeeper = t.Oname[j];
					}
					j++;
					i++;
				}
				if (i >= 30 && i <= 45)
				{
					getline(pak, t.TTname[k]);
					if (k == 0)
					{
						t.captan = t.TTname[k];
					}
					if (k == 1)
					{
						t.wicketkeeper = t.TTname[k];
					}
					if (k == 15)
					{
						t.coach = t.TTname[k];
						t.TTname[k] = ' ';
					}
					k++;
					i++;
				}
				
			}
			pak.close();
			system("cls");
			t.displayTeam();
			system("pause");
			system("cls");;
			break;
		case 2:
			p->addPlayer();
			system("pause");
			system("cls");
			break;
		case 3:
			p->removePlayer();
			system("pause");
			system("cls");
			break;
		case 4:
			p->searchPlayer();
			system("pause");
			system("cls");
			break;
		case 5:
			p->updatePlayer();
			system("pause");
			system("cls");
			break;
		case 6:
			t.updateCaptain();
			system("pause");
			system("cls");
			break;
		case 7:
			t.updateCoach();
			system("pause");
			system("cls");
			break;
		case 8:
			t.displayMatches();
			system("pause");
			system("cls");
			break;
		case 9:
			t.ViewStats();
			system("pause");
			system("cls");
			break;
		case 10:
			m.conductMatch();
			system("pause");
			system("cls");
			break;
		case 11:
			m.conductTournament();
			system("pause");
			system("cls");
			break;
		case 12:
			m.displayUpcomingMatches();
			system("pause");
			system("cls");
			break;
		case 13:
			m.displayRecentMatches();
			system("pause");
			system("cls");
			break;
		case 14:
			n.Rankings();
			system("pause");
			system("cls");
			break;
		case 15:
			cout << "Thank you for vising cricbuzz" << endl;
			SetConsoleTextAttribute(color, 7);
			exit(1);
		}
	}

	
}