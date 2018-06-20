#include "thread.h"
#include "main.h"

void
SimpleThread(int which)
{
  int num;
  char buffer[1024];
  for (num = 0; num < 3; num++) {
    buffer[0] = '\0';
    kernel->io_routines->Read(num, buffer);
    kernel->io_routines->Print(buffer);
  }
}

// Advances Nachos time.
void
AdvanceTime()
{
  while (1) {
    kernel->interrupt->OneTick();
    kernel->currentThread->Yield();
  }
}

void
ThreadTest()
{  
  Thread *t1 = new Thread("t1");
  t1->Fork((VoidFunctionPtr)SimpleThread, (void*)1);
  
  Thread *t2 = new Thread("t2");
  t2->Fork((VoidFunctionPtr)SimpleThread, (void*)2);
  
  AdvanceTime();
}
