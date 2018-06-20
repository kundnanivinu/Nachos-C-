# include<vikundna_agency.h>
# include<string>

struct Team
{
	int teamNo;
	char teamName[10];
	char teamState[10];
	int totalPlayers;
	struct PlayerNode* playerList;
	struct Team* next;	
};

struct PlayerNode
{
	int index;
	struct PlayerNode* next;
};

void addTeam(struct Team **root);
void addPlayerToTeam(struct Team **root);
void validateTeamName(struct Team **root, struct Team **newNode);
void displayTeam(struct Team **root);
void getPlayers(struct Team **newNode);
bool checkTeamExists(struct Team **root, char teamName[]);
void sortTeam(struct Team** root);
void sortedInsert(struct PlayerNode** head, struct PlayerNode* newNode);
void insertionSort(struct PlayerNode **rootPlayer);
void displayAllTeam(struct Team **root);
