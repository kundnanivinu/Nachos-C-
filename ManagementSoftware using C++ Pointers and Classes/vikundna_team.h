# include<vikundna_player.h>
# include<string>
# include<vector>

using namespace std;

class Team
{
	private:
		int teamNo;
		char teamName[10];
		char teamState[10];
		vector <long> playerList;
	public:

		// Destructor
		~Team();

		// Setters for class Team private members
		void setTeamNumber(int number);
		void setTeamName(char name[]);
		void setTeamState(char state[]);
		void addPlayer(long uniqueId);

		// Getters for class Team private members
		int getTeamNumber();
		char* getTeamName();
		char* getTeamState();
		long getPlayer(int i);
		int getNumberOfPlayers();

		// Valiadations
		void validateTeamName();
		void mySort(ManagePlayer& mp);
		bool checkPlayerAlreadyExists(long uniqueId);
		
};

class ManageTeam
{
	public:
		// Team Operations
		int getTeamsSize();
		void addTeam(ManagePlayer& mp);
		void addPlayerToTeam(ManagePlayer& mp);
		void displayTeam(ManagePlayer& mp);
		void getPlayers(Team& temp, ManagePlayer& mp);
		void sortTeam(ManagePlayer& mp);
		void displayAllTeam(ManagePlayer& mp);
		void freeMemory();
};

