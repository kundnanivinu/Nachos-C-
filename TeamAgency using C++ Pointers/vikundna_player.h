// Header file for vikundna_player.cc

# include<vikundna_agency.h>
# include<string>
using namespace std;

struct Player
{
	int index;
	char team[10];
	char firstName[10];
	char lastName[10];
	long uniqueId;
	char phoneNumber[10];
	float salary;
	char position[10]; 
	string address;
	
};

void addPlayer();
void findPlayer();
void findByName();
void findById();
void findByNumber();
void sortPlayers(struct Team **root);
void sortByName(struct Team **root);
void sortById(struct Team **root);
void sortBySalary(struct Team **root);
void validateName(struct Player *tempPlayer);
void validatePhone(struct Player *tempPlayer);
void validateId(struct Player *tempPlayer);
bool validateDigits(string number);
int getPlayerIndex(long uniqueId);
void displayPlayers();
void displayInfo(int index);
void copyPlayer(struct Player *tempPlayer, int playerCount);
void testData();
void updateIndices(struct Team **root, int present, int update);
