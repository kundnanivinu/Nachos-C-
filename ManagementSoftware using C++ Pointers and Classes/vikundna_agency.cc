
// Main File for Vinu Kundnani
// This file contains the main() program 
// TestData method is included in the Player File that initializes the static player array with 5 player information
// We can directly test Find, Sort, Make a Team and other functionalities 

# include<vikundna_agency.h>
# include<vikundna_team.h>
# include<stdlib.h>
# include<iostream>
# include<vector>

using namespace std;

int main()
{
	int option;
	char option2;
	
	ManagePlayer mp;

	cout << "\t\t\tCPS 400- Assignment 2\n";
	cout << "\t\tManagement Software- Sports Agency\n";
	cout << "\t\tTestData method is included in the Player File that initializes the static player array with 5 player information\n";
	cout << "\t\tWe can directly test Find, Sort, Make a Team and other functionalities\n";
	cout << "\t\tNet ID: vikundna \t\t SUID: 470316255";
	mp.testData();

	ManageTeam mt;

	do
	{
		system("clear");
		cout << "\t\t\tCPS 400- Assignment 2\n";
		cout << "\t\tManagement Software- Sports Agency\n";
		cout << "\t\tTestData method is included in the Player File that initializes the static player array with 5 player information\n";
		cout << "\t\tWe can directly test Find, Sort, Make a Team and other functionalities\n";
		cout << "\t\tNet ID: vikundna \t\t SUID: 470316255";
		cout << "\n\n*************MENU FOR TEAM AND PLAYER MANAGEMENT SOFTWARE****************";
		cout << "\n\n************************PLAYER SUB-MENU*********************************";
		cout << "\n\t1. Add a Player";
		cout << "\n\t2. Find a Player";
		cout << "\n\t3. Sort the Players";
		cout << "\n\n************************PLAYER SUB-MENU*********************************";
		cout << "\n\t4. Add a Team";
		cout << "\n\t5. Add a player to the Team";
		cout << "\n\t6. Display players of a team";
		cout << "\n\t7. Sort players of team(depending on index)";
		cout << "\n\t8. Display all the teams";
		cout << "\n\t9. Exit";
		cout << "\nEnter your choice:\t";
		cin >> option;
	
		switch(option)
		{
			case 1:
				system("clear");
				mp.addPlayer();
				break;
			case 2:
				system("clear");
				mp.findPlayer();
				break;
			case 3:
				system("clear");
				mp.sortPlayers();
				break;
			case 4:
				system("clear");
				mt.addTeam(mp);
				break;
			case 5:
				system("clear");
				mp.displayPlayers();	
				mt.addPlayerToTeam(mp);
				break;
			case 6:
				system("clear");
				mt.displayTeam(mp);
				break;
			case 7:
				system("clear");
				mt.sortTeam(mp);
				break;
			case 8:
				system("clear");
				mt.displayAllTeam(mp);
				break;
			case 9:
				exit(0);
				mp.freeMemory();
				mt.freeMemory();	
			default:
				cout << "\n\nIncorrect input..!";
		}

	
		cout << "\n\n Do you want to do continue managing? (Y/N):\t\t";
		cin >> option2;
	}while('y' == option2 || 'Y' == option2);


	return 0;
}
