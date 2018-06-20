# include<vikundna_agency.h>
# include<vikundna_player.h>
# include<vikundna_team.h>
# include<iostream>
# include<string.h>
# include<ctype.h>
# include<cstdlib>

static int teamCount= 0;

void addTeam(struct Team **root)
{
	struct Team* newNode = (struct Team*) malloc(sizeof(struct Team));
	struct Team* last= *root;
	
	cout << "\n\n************************Add a Team*********************************";
	
	newNode->teamNo= teamCount+1;
	newNode->totalPlayers = 0;
	validateTeamName(root, &newNode);

	cout << "\n Enter the state for which team plays:\t";
	cin >> newNode->teamState;
	
	cout << "\nGetting the players for the team\n";	
	displayPlayers();	
	getPlayers(&newNode);

	if(*root == NULL)
	{
		*root= newNode;
	}
	else
	{
		while(last->next != NULL)
			last= last->next;
		last->next= newNode;
	}
	
	newNode->next= NULL;
	teamCount++;
}

void addPlayerToTeam(struct Team **root)
{	
	struct Team* temp= *root;
	char name[10];
	long uniqueId;
	int index;
	cout << "\n\n************************Add Player to a Team*********************************";
	cout << "\n Enter the team name:\t";
	cin >> name;
	if(checkTeamExists(root, name))
	{
		cout << "\nEnter the player's unique id:\t";
		cin >> uniqueId;

		index= getPlayerIndex(uniqueId);
		if (99 == index)
		{
			cout << "Player with this uniqueId does not exists!! Please use lookup table for valid unique ids";
			addPlayerToTeam(root);
		}
		else
		{
			while(temp != NULL)
			{
				if(0 == strcmp(temp->teamName, name))
				{
					struct PlayerNode* newPlayer= (struct PlayerNode*) malloc(sizeof(struct PlayerNode));
					struct PlayerNode* last= temp->playerList;
					newPlayer->next= NULL;
					temp->totalPlayers++;
					newPlayer->index= index;
	
					if(NULL == temp->playerList)
					{
						temp->playerList= newPlayer;
					}
					else
					{
						while(last->next != NULL)
							last= last->next;
						last->next= newPlayer;
					}
				}
				temp=temp->next;
			}
		}
	}
}

void displayTeam(struct Team **root)
{
	struct Team* temp= *root;
	char teamName[10];
	cout << "\n\n************************Display Players Affiliated to a Team*********************************";
	cout << "\n Enter the team name:\t";
	cin >> teamName;
	if(checkTeamExists(root, teamName))
	{
		while(temp != NULL)
		{
			if(0 == strcmp(temp->teamName, teamName))
			{
				struct PlayerNode *temp2= temp->playerList;	
				while(temp2 != NULL)
				{
					displayInfo(temp2->index);
					temp2=temp2->next;
				}
			}
			temp= temp->next;
		}
	}	
}

void validateTeamName(struct Team **root, struct Team **newNode)
{
	struct Team *temp= *root;
	char name[10];
	cout << "\n Enter the team name:\t";
	cin >> name;
	
	while(temp != NULL)
	{
		if(0 == strcmp(temp->teamName, name))
		{
			cout << "\n\nTeam with name " << name << " already exists";
			validateTeamName(root, newNode);
		}
		temp=temp->next;
	}
	for(int  i = 0 ; i < strlen(name); i++)
	{
		if(!isalpha(name[i]))
		{
			cout << "Invalid charaters!! Characters can only be aplhabets";
			validateTeamName(root, newNode);
		}
	}
	strcpy((*newNode)->teamName, name);
}

void getPlayers(struct Team **newNode)
{
	long uniqueId;
	char option;
	int index;
	do
	{
		cout << "\nEnter the player's unique id:\t";
		cin >> uniqueId;
		
		index= getPlayerIndex(uniqueId);
		if (99 == index)
		{
			cout << "Player with this uniqueId does not exists!! Please use lookup table for valid unique ids";
			getPlayers(newNode);
		}
		else
		{
			struct PlayerNode* newPlayer= (struct PlayerNode*) malloc(sizeof(struct PlayerNode));
			struct PlayerNode* last= (*newNode)->playerList;
			newPlayer->next= NULL;
			(*newNode)->totalPlayers++;
			newPlayer->index= index;
	
			if(NULL == (*newNode)->playerList)
			{
				(*newNode)->playerList= newPlayer;
			}
			else
			{
				while(last->next != NULL)
					last= last->next;
				last->next= newPlayer;
				
			}
		}
		cout << "\n\n Do you want to do continue adding player to team? (Y/N):\t\t";
		cin >> option;
	}while('y' == option || 'Y' == option);	// coding convention to follow, constants on left side while comparison and variables on right
}

bool checkTeamExists(struct Team **root, char teamName[])
{
	struct Team* temp =*root;
	bool found= false;

	while(temp != NULL)
	{
		if(0 == strcmp(temp->teamName, teamName))
		{
			found = true;
		}
		temp=temp->next;
	}
	if(false == found)
	{
		cout << "\n\nTeam with name " << teamName << " does not exists";
	}
	return found;
}

void updateIndices(struct Team **root, int present, int update)
{
	struct Team* temp =*root;
	while(temp != NULL)
	{
		struct PlayerNode *temp2= temp->playerList;	
		while(temp2!= NULL)
		{
			if(temp2->index == present)
				temp2->index= update;
			else if(temp2->index == update)
				temp2->index= present;
			temp2=temp2->next;
		}
		temp= temp->next;
	}	
}

void insertionSort(struct PlayerNode **rootPlayer)
{
	struct PlayerNode *sorted = NULL;
	struct PlayerNode *curr = *rootPlayer;
	while(curr!=NULL)	
	{
		struct PlayerNode *next= curr->next;
		sortedInsert(&sorted, curr);
		curr= next;
	}
	*rootPlayer= sorted;
}

void sortedInsert(struct PlayerNode** head, struct PlayerNode* newNode)
{
	struct PlayerNode* current;
	if(*head == NULL || (*head)->index >= newNode->index)
	{
		newNode->next= *head;
		*head= newNode;
	}
	else
	{
		current= *head;
		while(current->next!= NULL && ((current->next->index) < newNode->index))
		{
			current= current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void sortTeam(struct Team** root)
{
	struct Team* temp =*root;
	char teamName[10];
	cout << "\n\n************************Sort Players of a Team*********************************";
	cout << "\n Enter the team name:\t";
	cin >> teamName;
	if(checkTeamExists(root, teamName))
	{
		while(temp != NULL)
		{
			if(0 == strcmp(temp->teamName, teamName))
			{
				struct PlayerNode* sort= temp->playerList;
				insertionSort(&sort);

				struct PlayerNode *temp2= sort;	
				while(temp2 != NULL)
				{
					displayInfo(temp2->index);
					temp2=temp2->next;
				}
			}
			temp= temp->next;
		}
	}
}

void displayAllTeam(struct Team **root)
{
	struct Team* temp= *root;
	cout << "\n\n************************Display all Teams Managed by Agency*********************************";
	while(temp != NULL)
	{
		cout <<"\nTeam Number:\t "<< temp->teamNo;
		cout <<"\nTeam Name:\t" << temp->teamName;
		cout <<"\nTeam State:\t" << temp->teamState;
		cout <<"\nTotal Players:\t" << temp->totalPlayers;
		cout << "\nPlayers of team";
		struct PlayerNode *temp2= temp->playerList;	
		while(temp2 != NULL)
		{
			displayInfo(temp2->index);
			temp2=temp2->next;
		}
		temp= temp->next;
	}	
}
