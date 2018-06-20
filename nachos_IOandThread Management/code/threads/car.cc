#include "car.h"
#include <string.h>

CarSpec :: CarSpec()
{
}
CarSpec :: CarSpec(const CarSpec& c)
{
	mpg= c.mpg;
	strcpy(this->name, c.name);
}
void CarSpec :: setMPG(double mpg)
{
	this->mpg= mpg;
}

void CarSpec :: setName(char *name)
{
	strcpy(this->name, name);
}

double CarSpec :: getMPG()
{
	return mpg;
}

char* CarSpec :: getName()
{
	return name;
}
