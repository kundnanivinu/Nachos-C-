# include<vikundna_team.h>
# include<iostream>
# include<algorithm>
# include<string.h>
# include<ctype.h>
# include<cstdlib>

using namespace std;
vector <Team> teams;

// Destructor
Team :: ~Team()
{
}

// Setters
void Team :: setTeamNumber(int number)
{
	teamNo= number;
}
void Team :: setTeamName(char name[])
{
	strcpy(teamName, name);
}
void Team :: setTeamState(char state[])
{
	strcpy(teamState, state);
}
void Team :: addPlayer(long uniqueId)
{
	playerList.push_back(uniqueId);
}

// Getters

int Team :: getTeamNumber()
{
	return teamNo;
}

char* Team :: getTeamName()
{
	return teamName;
}

char* Team :: getTeamState()
{
	return teamState;
}

long Team :: getPlayer(int i)
{
	return playerList.at(i);
}

int Team :: getNumberOfPlayers()
{
	return playerList.size();
}

// Validations and Sorting

void Team :: validateTeamName()
{
	bool duplicate= false;
	char name[10];
	cout << "\n Enter the team name:\t";
	cin >> name;
	
	for(int  i = 0 ; i < strlen(name); i++)
	{
		if(!isalpha(name[i]))
		{
			cout << "Invalid charaters!! Characters can only be aplhabets";
			this->validateTeamName();
		}
	}
	for(int i = 0 ; i < teams.size() ; i++)
	{
		if((0 == strcmp(teams[i].getTeamName(), name)))
		{
			duplicate= true;
			break;
		}
	}

	if(true == duplicate)
	{
		cout << "\n\nTeam with name " << name << " already exists";
		this->validateTeamName();
	}
	else
		this->setTeamName(name);
}

void Team :: mySort(ManagePlayer& mp)
{
	vector <long> tempList= this->playerList;
	sort(tempList.begin(), tempList.end());
	
	this->playerList= tempList;

	cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";	
	for(int i = 0 ; i < this->playerList.size(); i++)
	{
		mp.displayById(this->playerList[i]);
	}
}

bool Team :: checkPlayerAlreadyExists(long uniqueId)
{
	vector <long> :: iterator it;
	it = find(this->playerList.begin(), this->playerList.end(), uniqueId);

	if(it != this->playerList.end())
		return true;
	else
		return false;
}

// Team Operations

int ManageTeam :: getTeamsSize()
{
	return teams.size();
}

void ManageTeam :: addTeam(ManagePlayer& mp)
{
	Team tempTeam;
	char str[10];
	string tmpStr;
	cout << "\n\n************************Add a Team*********************************";
	
	int size= getTeamsSize();
	tempTeam.setTeamNumber(size++);

	tempTeam.validateTeamName();

	cout << "\n Enter the state for which team plays:\t";
	cin >> str;
	tempTeam.setTeamState(str);
	
	cout << "\nGetting the players for the team\n";	
	mp.displayPlayers();	
	getPlayers(tempTeam, mp);

	teams.push_back(tempTeam);
	displayAllTeam(mp);
}

void ManageTeam :: getPlayers(Team& temp, ManagePlayer& mp)
{
	long uniqueId;
	char option;
	bool flag;

	do
	{
		cout << "\nEnter the player's unique id:\t";
		cin >> uniqueId;
		
		flag= mp.checkPlayer(uniqueId);
		if (!flag)
		{
			cout << "Player with this uniqueId does not exists!! Please use lookup table for valid unique ids";
			getPlayers(temp, mp);
		}
		else
		{
			if(!temp.checkPlayerAlreadyExists(uniqueId))
				temp.addPlayer(uniqueId);
			else
			{
				cout << "Player with this uniqueId already exists in the team!! Please use lookup table for other valid unique ids";
			}
		}
		cout << "\n\n Do you want to do continue adding player to team? (Y/N):\t\t";
		cin >> option;
	}while('y' == option || 'Y' == option);
}

void ManageTeam :: addPlayerToTeam(ManagePlayer& mp)
{	
	char name[10];
	long uniqueId;
	bool flag;

	cout << "\n\n************************Add Player to a Team*********************************";	
	cout << "\n Enter the team name:\t";
	cin >> name;

	cout << "\nEnter the player's unique id:\t";
	cin >> uniqueId;

	flag= mp.checkPlayer(uniqueId);
	if (!flag)
	{
		cout << "Player with this uniqueId does not exists!! Please use lookup table for valid unique ids";
		addPlayerToTeam(mp);
	}
	else
	{
		flag= false;
		for(int i = 0 ; i < teams.size() ; i++)
		{
			if(0 == strcmp(teams[i].getTeamName(), name))
			{
				flag= true;
				if(!teams[i].checkPlayerAlreadyExists(uniqueId))
					teams[i].addPlayer(uniqueId);
				else
				{
					cout << "Player with this uniqueId already exists in the team!! Please use lookup table for other valid unique ids";
				}
			}
		}
		if(!flag)
		{
			cout << "Team with name " << name << " does not exists!!";
		}
	}
}

void ManageTeam :: displayTeam(ManagePlayer& mp)
{
	char teamName[10];
	bool flag= false;
	cout << "\n\n************************Display Players Affiliated to a Team*********************************";
	
	cout << "\n Enter the team name:\t";
	cin >> teamName;

	for(int i = 0 ; i < teams.size() ; i++)
	{
		if(0 == strcmp(teams[i].getTeamName(), teamName))
		{
			flag= true;
			cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";	
			for(int j = 0; j < teams[i].getNumberOfPlayers(); j++)
			{
				mp.displayById(teams[i].getPlayer(j));
			}
		}
	}
	if(!flag)
	{
		cout << "Team with name " << teamName << " does not exists!!";
	}
}

void ManageTeam :: sortTeam(ManagePlayer& mp)
{
	char teamName[10];
	bool flag= false;

	cout << "\n\n************************Sort Players of a Team*********************************";
	cout << "\n\n** Since we are just storing uniqueId of Players in the PlayerList of Team **";
	cout << "\n\n** We will just sort by uniqueId using std::sort on vectort PlayerList **";
	cout << "\n Enter the team name:\t";
	cin >> teamName;
	
	for(int i = 0 ; i < teams.size() ; i++)
	{
		if(0 == strcmp(teams[i].getTeamName(), teamName))
		{
			flag= true;
			teams[i].mySort(mp);
		}
	}
	if(!flag)
	{
		cout << "Team with name " << teamName << " does not exists!!";
	}

}

void ManageTeam :: displayAllTeam(ManagePlayer& mp)
{
	cout << "\n\n************************Display all Teams Managed by Agency*********************************";
	for(int i = 0 ; i < teams.size() ; i++)
	{
		cout <<"\nTeam Number:\t "<< teams[i].getTeamNumber();
		cout <<"\nTeam Name:\t" << teams[i].getTeamName();
		cout <<"\nTeam State:\t" << teams[i].getTeamState();
		cout <<"\nTotal Players:\t" << teams[i].getNumberOfPlayers();
		cout << "\nPlayers of team";
		cout << "\nUniqueId\tFirst Name\tLast Name\tTeam\tPhoneNumber\tSalary\tPosition\tAddress";	
		for(int j = 0 ; j < teams[i].getNumberOfPlayers(); j++)
		{
			mp.displayById(teams[i].getPlayer(j));
		}
	}	
}

void ManageTeam :: freeMemory()
{
	delete &teams;
}
