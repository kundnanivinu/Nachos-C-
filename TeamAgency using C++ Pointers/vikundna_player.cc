# include<vikundna_player.h>
# include <stdlib.h>
# include<iostream>
# include<string.h>
# include<ctype.h>

#define MAX 50
using namespace std;

static struct Player players[50];
static int playerCount=0;

void addPlayer()
{
	struct Player tempPlayer;
	cout << "\n\n************************Add a Player*********************************";

	validateName(&tempPlayer);

	validateId(&tempPlayer);

	validatePhone(&tempPlayer);

	cout << "\n Enter the team name the player is affliated to:\t";
	cin >> tempPlayer.team;
	cout << "\n Enter the postion of the player in the team:\t";
	cin >> tempPlayer.position;
	cin.ignore();
	cout << "\n Enter the address of the player:\t";	
	getline(cin, tempPlayer.address);
	cin.ignore();
	cout << "\n Enter the salary for the player:\t";
	cin >> tempPlayer.salary;

	copyPlayer(&tempPlayer, playerCount);
	playerCount++;

	displayPlayers();
}

void findPlayer()
{
	int option;
	char option2;
	
	cout << "\t\t\tCPS 400- Assignment 2\n";
	cout << "\t\tManagement Software- Sports Agency\n";
	cout << "\t\tNet ID: vikundna \t\t SUID: 470316255";
	do
	{
		cout << "\n\n*************MENU FOR TEAM AND PLAYER MANAGEMENT SOFTWARE****************";
		cout << "\n\n************************FIND A PLAYER SUB-MENU*********************************";
		cout << "\n\t1. Find a Player by Name";
		cout << "\n\t2. Find a Player by Unique ID";
		cout << "\n\t3. Find a Player by Phone Number";
		cout << "\n\t4. Return to main menu";
		cout << "\nEnter your choice:\t";
		cin >> option;
		switch(option)
		{
			case 1:
				findByName();
				break;
			case 2:
				findById();
				break;
			case 3:
				findByNumber();
				break;
			case 4:
				//mainMenu();
				break;
			default:
				cout << "\n\nIncorrect input..!";
		}

		cout << "\n\n Do you want to do continue looking for another player? (Y/N):\t\t";
		cin >> option2;
	}while('y' == option2 || 'Y' == option2);
}

void findByName()
{
	char firstName[10], lastName[10]; 
	cout << "\n\nEnter the player's first name:\t";
	cin >> firstName;
	cout << "\n\nEnter the player's last name:\t";
	cin >> lastName;

	for(int i = 0; i < playerCount; i++)
	{
		if((0 == strcmp(players[i].firstName, firstName)) && (0 == strcmp(players[i].lastName, lastName)))
		{
			cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";
			cout << "\n" << players[i].uniqueId <<"\t\t"<< players[i].firstName <<"\t\t" << players[i].lastName << "\t\t" << players[i].team << "\t" << players[i].phoneNumber << "\t" << players[i].salary << "\t" << players[i].position << "\t\t" << players[i].address;
		}
	}
}

void findById()
{
	long uniqueID; 
	bool playerFound= false;
	cout << "\n\nEnter the player's uniqueID:\t";
	cin >> uniqueID;

	for(int i = 0; i < playerCount; i++)
	{
		if(players[i].uniqueId== uniqueID)
		{
			playerFound= true;
			cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";
			cout << "\n" << players[i].uniqueId <<"\t\t"<< players[i].firstName <<"\t\t" << players[i].lastName << "\t\t" << players[i].team << "\t" << players[i].phoneNumber << "\t" << players[i].salary << "\t" << players[i].position << "\t\t" << players[i].address;
			break;
		}
	}
	if(false== playerFound)
	{
		cout << "Player with id " << uniqueID << " does not exists!";	
	}
}
void findByNumber()
{
	char phoneNumber[10]; 
	bool playerFound= false;
	cout << "\n\nEnter the player's phone number:\t";
	cin >> phoneNumber;

	for(int i = 0; i < playerCount; i++)
	{
		if((0 == strcmp(players[i].phoneNumber, phoneNumber)))
		{
			playerFound= true;
			cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";
			cout << "\n" << players[i].uniqueId <<"\t\t"<< players[i].firstName <<"\t\t" << players[i].lastName << "\t\t" << players[i].team << "\t" << players[i].phoneNumber << "\t" << players[i].salary << "\t" << players[i].position << "\t\t" << players[i].address;
			break;
		}
	}
	if(false== playerFound)
	{
		cout << "Player with phone number " << phoneNumber << " does not exists!";	
	}
}

void sortPlayers(struct Team **root)
{
	int option;
	char option2;
	
	cout << "\t\t\tCPS 400- Assignment 2\n";
	cout << "\t\tManagement Software- Sports Agency\n";
	cout << "\t\tNet ID: vikundna \t\t SUID: 470316255";
	do
	{
		cout << "\n\n*************MENU FOR TEAM AND PLAYER MANAGEMENT SOFTWARE****************";
		cout << "\n\n************************SORT PLAYER ARRAY SUB-MENU*********************************";
		cout << "\n\t1. Sort players by Name";
		cout << "\n\t2. Sort players by Unique ID";
		cout << "\n\t3. Sort players by Salary";
		cout << "\n\t4. Return to main menu";
		cout << "\nEnter your choice:\t";
		cin >> option;
		switch(option)
		{
			case 1:
				system("clear");
				sortByName(root);
				break;
			case 2:
				system("clear");
				sortById(root);
				break;
			case 3:
				system("clear");
				sortBySalary(root);
				break;
			case 4:
				//mainMenu();
				break;
			default:
				cout << "\n\nIncorrect input..!";
		}
	
		cout << "\n\n Do you want to continue sorting? (Y/N):\t\t";
		cin >> option2;
	}while('y' == option2 || 'Y' == option2);
}
void sortByName(struct Team **root)
{
	struct Player tempPlayer;
	int i,j, min_idx;
	for(i = 0; i < playerCount-1; i ++)
	{
		min_idx = i;
		for(j=i+1; j < playerCount; j++)
		{
			if((strcmp(players[j].firstName, players[min_idx].firstName)<0))
				min_idx= j;
		}
		tempPlayer = players[i];
		players[i] = players[min_idx];
		players[min_idx]=tempPlayer;
		updateIndices(root, i, min_idx);
	}
	displayPlayers();
}
void sortById(struct Team **root)
{
	struct Player tempPlayer;
	int i,j, min_idx;
	for(i = 0; i < playerCount-1; i ++)
	{
		min_idx = i;
		for(j=i+1; j < playerCount; j++)
		{
			if(players[j].uniqueId < players[min_idx].uniqueId)
				min_idx= j;
		}
		tempPlayer = players[i];
		players[i] = players[min_idx];
		players[min_idx]=tempPlayer;
		updateIndices(root, i, min_idx);
	}
	displayPlayers();
}
void sortBySalary(struct Team **root)
{
	struct Player tempPlayer;
	
	int i,j, min_idx;
	for(i = 0; i < playerCount-1; i ++)
	{
		min_idx = i;
		for(j=i+1; j < playerCount; j++)
		{
			if(players[j].salary > players[min_idx].salary)
				min_idx= j;
		}
		tempPlayer = players[i];
		players[i] = players[min_idx];
		players[min_idx]=tempPlayer;
		updateIndices(root, i, min_idx);
	}
	displayPlayers();
}
void validateName(struct Player *tempPlayer)
{
	char firstName[10], lastName[10];
	cout << "\n Enter the first name of the player:\t";
	cin >> firstName;

	cout << "\n Enter the last name of the player:\t";
	cin >> lastName;
	
	bool flag= true;
	for(int  i = 0 ; i < strlen(firstName); i++)
	{
		if(!isalpha(firstName[i]))
		{
			cout << "Invalid charaters in FirstName!! Characters can only be aplhabets";
			flag= false;
		}
	}
	for(int  i = 0 ; i < strlen(lastName); i++)
	{
		if(!isalpha(firstName[i]))
		{
			cout << "Invalid charaters in lastName!! Characters can only be aplhabets";
			flag= false;
		}
	}
	if(true == flag){
		strcpy(tempPlayer->firstName, firstName);
		strcpy(tempPlayer->lastName, lastName);
	}
	if(false == flag)
	{
		validateName(tempPlayer);
	}
}
void validatePhone(struct Player *tempPlayer)
{
	char phoneNumber[10];
	bool duplicate= false;
	cin.ignore();
	cout << "\n Enter the phone number of the player:\t";
	cin >> phoneNumber;

	for(int i = 0; i < playerCount; i++)
	{
		if((0 == strcmp(players[i].phoneNumber, phoneNumber)))
		{
			duplicate= true;
			break;
		}
	}
	if(strlen(phoneNumber) != 10)
	{
		cout << "Invalid Length!! Length can only be 10";
		validatePhone(tempPlayer);
	}
	else if(true == duplicate)
	{
		cout << "\n\nPhone number already exists.. 2 players cannot have same number!";
		validatePhone(tempPlayer);
	}
	else if(false == validateDigits(phoneNumber))
	{
		cout << "Invalid digits!! Digits can be between 0-9";
		validatePhone(tempPlayer);
	}
	else
		strcpy(tempPlayer->phoneNumber, phoneNumber);
}
void validateId(struct Player *tempPlayer)
{
	long uniqueId;
	bool duplicate= false;

	cin.ignore();
	cout << "\n Enter the unique id for the player:\t";
	cin >> uniqueId;

	for(int i = 0; i < playerCount; i++)
	{
		if(players[i].uniqueId == uniqueId)
		{
			duplicate= true;
			break;
		}
	}
	if(true == duplicate)
	{
		cout << "\n\nID already exists.. 2 players cannot have same id!";
		validateId(tempPlayer);
	}
	else
		tempPlayer->uniqueId= uniqueId;
}

bool validateDigits(string number)
{
	for(int  i = 0 ; i < 5; i++)
	{
		if(number[i] < '0' || number[i] > '9')
		{
			return false;
		}
	}
	return true;
}

int getPlayerIndex(long uniqueId)
{
	bool playerFound= false;
	for(int i = 0; i < playerCount; i++)
	{
		if(players[i].uniqueId== uniqueId)
		{
			playerFound= true;
			return (i);
		}
	}
	if(false== playerFound)
	{
		cout << "Player with id " << uniqueId << "does not exists!";	
	}
	return 99;
}

void displayPlayers()
{
	cout << "\nDisplaying all the players affliated to the agency..";
	cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";
	for(int i = 0 ; i < playerCount ; i++)
	{
		cout << "\n" << players[i].uniqueId <<"\t\t"<< players[i].firstName <<"\t\t" << players[i].lastName << "\t\t" << players[i].team << "\t" << players[i].phoneNumber << "\t" << players[i].salary << "\t" << players[i].position << "\t\t" << players[i].address;
	}
}

void displayInfo(int i)
{
	cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";	
	cout << "\n" << players[i].uniqueId <<"\t\t"<< players[i].firstName <<"\t\t" << players[i].lastName << "\t\t" << players[i].team << "\t" << players[i].phoneNumber << "\t" << players[i].salary << "\t" << players[i].position << "\t\t" << players[i].address;
}

void copyPlayer(struct Player *tempPlayer, int playerCount)
{
	strcpy(players[playerCount].firstName, tempPlayer->firstName);
	strcpy(players[playerCount].lastName, tempPlayer->lastName);
	players[playerCount].uniqueId= tempPlayer->uniqueId;
	strcpy(players[playerCount].phoneNumber, tempPlayer->phoneNumber);
	strcpy(players[playerCount].position, tempPlayer->position);
	strcpy(players[playerCount].team, tempPlayer->team);
	players[playerCount].address= tempPlayer->address;
	players[playerCount].salary= tempPlayer->salary;
}

void testData()
{
	playerCount= 5;
	for(int i = 0 ; i < 5; i++)
	{
		players[i].uniqueId= i;
		players[i].salary= 500.09+i;
		strcpy(players[i].position, "trial");
		strcpy(players[i].team, "team");
		players[i].address= "lancaster";

	}
	strcpy(players[0].firstName, "vinu");
	strcpy(players[0].lastName, "kund");
	strcpy(players[0].phoneNumber, "9960241888");
	strcpy(players[1].firstName, "aarti");
	strcpy(players[1].lastName, "kund");
	strcpy(players[1].phoneNumber, "9890732959");
	strcpy(players[2].firstName, "varsha");
	strcpy(players[2].lastName, "kund");
	strcpy(players[2].phoneNumber, "9922989794");
	strcpy(players[3].firstName, "rahul");
	strcpy(players[3].lastName, "kund");
	strcpy(players[3].phoneNumber, "9960241887");
	strcpy(players[4].firstName, "deepak");
	strcpy(players[4].lastName, "kund");
	strcpy(players[4].phoneNumber, "1234567890");
	
}
