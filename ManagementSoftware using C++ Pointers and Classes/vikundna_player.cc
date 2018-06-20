# include<vikundna_player.h>
# include<stdlib.h>
# include<iostream>
# include<vector>
# include<string.h>

using namespace std;

vector<Player> players;

//Copy and Default Constructor
Player :: Player()
{
}
Player :: Player(const Player &tempPlayer)
{
	strcpy(this->firstName, tempPlayer.firstName);
	strcpy(this->lastName, tempPlayer.lastName);
	this->uniqueId= tempPlayer.uniqueId;
	strcpy(this->phoneNumber, tempPlayer.phoneNumber);
	strcpy(this->position, tempPlayer.position);
	strcpy(this->team, tempPlayer.team);
	this->address= tempPlayer.address;
	this->salary= tempPlayer.salary;
}

//Destructor
Player :: ~Player()
{	
}

//Setter functions for the private variables
void Player :: setName(char firstName[], char lastName[])
{
	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
}

void Player :: setTeam(char team[])
{
	strcpy(this->team, team);
}

void Player :: setUniqueId(long uniqueId)
{
	this->uniqueId= uniqueId;
}

void Player :: setPhoneNumber(char phoneNumber[])
{
	strcpy(this->phoneNumber, phoneNumber);
}

void Player :: setSalary(float salary)
{
	this->salary = salary;
}

void Player :: setPosition(char position[])
{
	strcpy(this->position, position);
}

void Player :: setAddress(string address)
{
	this->address= address;
}

//Getters for Player private data members
char* Player :: getFirstName()
{
	return firstName;
}
char* Player :: getLastName()
{
	return lastName;
}
char* Player :: getPhoneNumber()
{
	return phoneNumber;
}
char* Player :: getPosition()
{
	return position;
}
char* Player :: getTeam()
{
	return team;
}
string Player :: getAddress()
{
	return address;
}
long Player :: getUniqueId()
{
	return uniqueId;
}
float Player :: getSalary()
{
	return salary;
}

// Validations on Player Objects

void Player :: validateName()
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
		if(!isalpha(lastName[i]))
		{
			cout << "Invalid charaters in lastName!! Characters can only be aplhabets";
			flag= false;
		}
	}
	if(true == flag){
		this->setName(firstName, lastName);
	}
	if(false == flag)
	{
		validateName();
	}
}
void Player :: validatePhone()
{
	char phoneNumber[10];
	bool duplicate= false;

	cin.ignore();
	cout << "\n Enter the phone number of the player:\t";
	cin >> phoneNumber;

	for(int i = 0 ; i < players.size() ; i++)
	{
		if((0 == strcmp(players[i].getPhoneNumber(), phoneNumber)))
		{
			duplicate= true;
			break;
		}
	}
	if(strlen(phoneNumber) != 10)
	{
		cout << "Invalid Length!! Length can only be 10";
		this->validatePhone();
	}
	else if(true == duplicate)
	{
		cout << "\n\nPhone number already exists.. 2 players cannot have same number!";
		this->validatePhone();
	}
	else if(false == validateDigits(phoneNumber))
	{
		cout << "Invalid digits!! Digits can be between 0-9";
		this->validatePhone();
	}
	else
		this->setPhoneNumber(phoneNumber);
}
void Player :: validateId()
{
	long uniqueId;
	bool duplicate= false;

	cin.ignore();
	cout << "\n Enter the unique id for the player:\t";
	cin >> uniqueId;

	//vector <Player> :: iterator i;

	//for(i = players.begin() ; i != players.end() ; i++)
	for(int i = 0 ; i < players.size() ; i++)
	{
		if(players[i].getUniqueId() == uniqueId)
		{
			duplicate= true;
			break;
		}
	}
	if(true == duplicate)
	{
		cout << "\n\nID already exists.. 2 players cannot have same id!";
		this->validateId();
	}
	else
		this->setUniqueId(uniqueId);
}

bool Player :: validateDigits(char number[])
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


//Operations on Player vector
void ManagePlayer :: addPlayer()
{
	char team[10], position[10];
	string address;
	float salary;

	Player tempPlayer;

	cout << "\n\n************************Add a Player*********************************";

	tempPlayer.validateName();

	tempPlayer.validateId();

	tempPlayer.validatePhone();

	cout << "\n Enter the team name the player is affliated to:\t";
	cin >> team;
	tempPlayer.setTeam(team);

	cout << "\n Enter the postion of the player in the team:\t";
	cin >> position;
	tempPlayer.setPosition(position);

	cin.ignore();
	cout << "\n Enter the address of the player:\t";	
	getline(cin, address);
	tempPlayer.setAddress(address);

	cin.ignore();
	cout << "\n Enter the salary for the player:\t";
	cin >> salary;
	tempPlayer.setSalary(salary);

	Player p= tempPlayer;
	players.push_back(p);

	displayPlayers();
}

void ManagePlayer :: findPlayer()
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
			default:
				cout << "\n\nIncorrect input..!";
		}

		cout << "\n\n Do you want to do continue looking for another player? (Y/N):\t\t";
		cin >> option2;
	}while('y' == option2 || 'Y' == option2);
}

void ManagePlayer :: findByName()
{
	bool playerFound= false;
	char firstName[10], lastName[10]; 
	cout << "\n\nEnter the player's first name:\t";
	cin >> firstName;
	cout << "\n\nEnter the player's last name:\t";
	cin >> lastName;

	for(int i=0; i< players.size(); i++)
	{
		if((0 == strcmp(players[i].getFirstName(), firstName)) && (0 == strcmp(players[i].getLastName(), lastName)))
		{
			playerFound= true;
			displayInfo(i);
			break;
		}
	}
	if(false== playerFound)
	{
		cout << "Player with name " << firstName << " " << lastName << " does not exists!";	
	}
}

void ManagePlayer :: findById()
{
	long uniqueID; 
	bool playerFound= false;
	cout << "\n\nEnter the player's uniqueID:\t";
	cin >> uniqueID;

	for(int i=0; i< players.size(); i++)
	{
		if(players[i].getUniqueId() == uniqueID)
		{
			playerFound= true;
			displayInfo(i);
			break;
		}
	}
	if(false== playerFound)
	{
		cout << "Player with id " << uniqueID << " does not exists!";	
	}
}
void ManagePlayer :: findByNumber()
{
	char phoneNumber[10]; 
	bool playerFound= false;
	cout << "\n\nEnter the player's phone number:\t";
	cin >> phoneNumber;

	for(int i=0; i< players.size(); i++)
	{
		if((0 == strcmp(players[i].getPhoneNumber(), phoneNumber)))
		{
			playerFound= true;
			displayInfo(i);
			break;
		}
	}
	if(false== playerFound)
	{
		cout << "Player with phone number " << phoneNumber << " does not exists!";	
	}
}

void ManagePlayer :: sortPlayers()
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
		cout << "\nEnter your choice:\t";
		cin >> option;
		switch(option)
		{
			case 1:
				system("clear");
				sortByName();
				break;
			case 2:
				system("clear");
				sortById();
				break;
			case 3:
				system("clear");
				sortBySalary();
				break;
			default:
				cout << "\n\nIncorrect input..!";
		}
	
		cout << "\n\n Do you want to continue sorting? (Y/N):\t\t";
		cin >> option2;
	}while('y' == option2 || 'Y' == option2);
}

void ManagePlayer :: sortByName()
{
	Player tempPlayer;
	int min_idx;

	for(int i = 0 ; i < players.size() ; i++)
	{
		min_idx = i;
		for(int j = i+1 ; j < players.size() ; j++)
		{
			if((strcmp(players[j].getFirstName(), players[min_idx].getFirstName())<0))
				min_idx= j;
		}
		tempPlayer = players[i];
		players[i] = players[min_idx];
		players[min_idx] = tempPlayer;
	}
	displayPlayers();
}

void ManagePlayer :: sortById()
{
	Player tempPlayer;
	int min_idx;

	for(int i = 0 ; i < players.size() ; i++)
	{
		min_idx = i;
		for(int j = i+1 ; j < players.size() ; j++)
		{
			if(players[j].getUniqueId() < players[min_idx].getUniqueId())
				min_idx= j;
		}
		tempPlayer = players[i];
		players[i] = players[min_idx];
		players[min_idx] = tempPlayer;
	}
	displayPlayers();
}

void ManagePlayer :: sortBySalary()
{
	Player tempPlayer;
	
	int min_idx;

	for(int i = 0 ; i < players.size() ; i++)
	{
		min_idx = i;
		for(int j = i+1 ; j < players.size() ; j++)
		{
			if(players[j].getSalary() > players[min_idx].getSalary())
				min_idx= j;
		}
		tempPlayer = players[i];
		players[i] = players[min_idx];
		players[min_idx] = tempPlayer;
	}
	displayPlayers();
}

bool ManagePlayer :: checkPlayer(long uniqueId)
{
	for(int j = 0 ; j < players.size() ; j++)
	{
		if(players[j].getUniqueId() == uniqueId)
			return true;
	}
	return false;
}

void ManagePlayer :: displayPlayers()
{
	cout << "\nDisplaying all the players affliated to the agency..";
	cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";

	for(int i = 0 ; i < players.size(); i++)
	{
		cout << "\n" << players[i].getUniqueId() <<"\t\t"<< players[i].getFirstName() <<"\t\t" << players[i].getLastName() << "\t\t" << players[i].getTeam() << "\t" << players[i].getPhoneNumber() << "\t" << players[i].getSalary() << "\t" << players[i].getPosition() << "\t\t" << players[i].getAddress();
	}
}

void ManagePlayer :: displayById(long uniqueId)
{
	for(int i = 0 ; i < players.size(); i++)
	{
		if(players[i].getUniqueId() == uniqueId)
		{
			cout << "\n" << players[i].getUniqueId() <<"\t\t"<< players[i].getFirstName() <<"\t\t" << players[i].getLastName() << "\t\t" << players[i].getTeam() << "\t" << players[i].getPhoneNumber() << "\t" << players[i].getSalary() << "\t" << players[i].getPosition() << "\t\t" << players[i].getAddress();
		}
	}
}

void ManagePlayer :: displayInfo(int i)
{
	Player tempPlayer= players.at(i);
	cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";	
	cout << "\n" << tempPlayer.getUniqueId() <<"\t\t"<< tempPlayer.getFirstName() <<"\t\t" << tempPlayer.getLastName() << "\t\t" << tempPlayer.getTeam() << "\t" << tempPlayer.getPhoneNumber() << "\t" << tempPlayer.getSalary() << "\t" << tempPlayer.getPosition() << "\t\t" << tempPlayer.getAddress();
}

void ManagePlayer :: testData()
{
	char key;
	for(int i = 0 ; i < 5; i++)
	{
		Player tempPlayer;
		tempPlayer.setUniqueId(i);
		tempPlayer.setSalary( 500.09+i);
		tempPlayer.setPosition("trial");
		tempPlayer.setTeam("team");
		tempPlayer.setAddress("lancaster");

		players.push_back(tempPlayer);

	}
	players[0].setName("vinu", "kund");
	players[0].setPhoneNumber("9960241888");
	players[1].setName("aarti", "kund");
	players[1].setPhoneNumber("9890732959");
	players[2].setName("varsha", "kund");
	players[2].setPhoneNumber("9922989794");
	players[3].setName("rahul", "kund");
	players[3].setPhoneNumber("9960241887");
	players[4].setName("deepak", "kund");
	players[4].setPhoneNumber("1234567890");

	displayPlayers();
	cout << "\n\n**Sort by name on players**";
	sortByName();
	cout <<"\n\nHit a key to continue..\t";
	cin >> key;
	cout << "\n\n**Sort by salary on players**";
	sortBySalary();
	cout <<"\n\nHit a key to continue..\t";
	cin >> key;
	cout << "\n\n**Sort by unique id on players**";
	sortById();
	cout <<"\n\nHit a key to continue..\t";
	cin >> key;
	
}

void ManagePlayer :: freeMemory()
{
	delete &players;
}



