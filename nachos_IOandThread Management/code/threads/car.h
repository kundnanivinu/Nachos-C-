#include <string.h>

class CarSpec
{
	private:
		double mpg;
		char name[40];
	public:
		CarSpec();
		CarSpec(const CarSpec& c);
		void setMPG(double mpg);
		void setName(char *name);
		double getMPG();
		char* getName();	
};
