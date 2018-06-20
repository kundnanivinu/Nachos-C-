#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "car.h"
#include "file_management.h"
#include "fstream"
#include "list.h"
#include "stdlib.h"
#include "string"

void SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
        printf("*** thread %d looped %d times\n", which, num);
        kernel->currentThread->Yield();
    }
}

static int CarCompare(CarSpec *c1, CarSpec *c2) {
    if (c1->getMPG() > c2->getMPG()) return -1;
    else if (c1->getMPG() == c2->getMPG()) return 0;
    else return 1;
}

CarSpec* create_CarSpec(const std::string& line)
{
  CarSpec *c= new CarSpec();
  std::string mpg;
  std::string name;
  char *temp;

  int delimiter = line.find(' ');
  mpg= line.substr(0, delimiter);
  c->setMPG(atof(mpg.c_str()));
  name= line.substr(delimiter + 1);
  temp= (char *)name.c_str();
  c->setName(temp);

  return c;
}

static void PrintCar (CarSpec *c)
{
    cout<< "MPG :\t"<< c->getMPG() << endl;
    cout<< "Name :\t"<< c->getName() << endl;
    cout << endl;
}

void ThreadTest()
{
    /*std::string line;
    std::ifstream infile;
    SortedList<CarSpec *> *sortList;		
    sortList = new SortedList<CarSpec *>(CarCompare);

    infile.open("./car.txt");

    while (std::getline(infile, line)) 
    {
        CarSpec *temp= create_CarSpec(line);
	sortList->Insert(temp);
	CarSpec *car = new CarSpec();
    }
    sortList->Apply(PrintCar);

    Thread *t = new Thread("forked thread");
    t->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    
    SimpleThread(0);*/

    FileManagement HD1(10);
    cout << "\n****CREATED HARDDISK WITH BLOCKS:\t" << HD1.total_blocks;
    HD1.create(0, 3);
    HD1.create(1, 2);
    HD1.create(2, 3);
    HD1.create(3, 4);
    HD1.remove(1);
    HD1.create(4, 4);

    FileManagement HD2(20);
    cout << "\n\n\n****CREATED HARDDISK WITH BLOCKS:\t" << HD2.total_blocks;
    HD2.create(0, 6);
    HD2.create(1, 3);
    HD2.create(2, 9);
    HD2.create(3, 5);
    HD2.remove(0);
    HD2.remove(0);
    HD2.create(4,4);
    HD2.remove(3);
}
