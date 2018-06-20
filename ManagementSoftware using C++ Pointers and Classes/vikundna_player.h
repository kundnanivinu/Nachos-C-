// Header file for vikundna_player.cc

# include<string>

using namespace std;

class Player
{
	private:
		char team[10];
		char firstName[10];
		char lastName[10];
		long uniqueId;
		char phoneNumber[10];
		float salary;
		char position[10];
		string address;

	public:

		//Copy and Default Constructor
		Player();
		Player(const Player &tempPlayer);

		//Destructor
		~Player();

		//Setters for the private data members
		void setName(char firstName[], char lastName[]);
		void setTeam(char team[]);
		void setUniqueId(long uniqueId);
		void setPhoneNumber(char phoneNumber[]);
		void setSalary(float salary);
		void setPosition(char position[]);
		void setAddress(string address);

		char* getFirstName();
		char* getLastName();
		char* getPhoneNumber();
		char* getPosition();
		char* getTeam();
		string getAddress();
		long getUniqueId();
		float getSalary();
		

		//Validation on Player Data Members
		void validateName();
		void validatePhone();
		void validateId();
		bool validateDigits(char number[]);

};

class ManagePlayer
{
	public:
		void addPlayer();
		void findPlayer();
		void findByName();
		void findById();
		void findByNumber();
		void sortPlayers();
		void sortByName();
		void sortById();
		void sortBySalary();
		bool checkPlayer(long uniqueId);
		void displayPlayers();
		void displayById(long uniqueId);
		void displayInfo(int i);
		void testData();
		void freeMemory();
};


