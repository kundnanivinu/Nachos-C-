// io.h
//  For details of the classes, see the descriptions of Project 1, available on
//  Blackboard.
#ifndef IO_ROUTINES_H
#define IO_ROUTINES_H

#include "list.h"
#include "thread.h"

#define KERNEL_BUF_SZ 4096

enum Operation {PRINT, READ};

class IO;
struct IOQueueItem;

class IORoutines {
public:
  IORoutines(IO* io_interface);
  void Print(const char* message); // simulated print system call
  void Read(int message_index, char* buffer); // simulated read system call
  void IOInterruptHandler(IOQueueItem* done); // handles IO interrupts
private:
  IO* io;
};

struct IOQueueItem {
  Operation operation; // type of operation
  Thread* thread; // pointer to the thread that issued this IO request
  char kernel_buffer[KERNEL_BUF_SZ]; // buffer managed by kernel
  char* user_buffer; // buffer managed by user program
  int message_index; // index of the message to read
  int done_time; // for simulation purpose
};

class IO {
public:
  IO();
  ~IO();
  void SimulateIO(); // for simulation purpose
  void SetIORoutines(IORoutines* routines); // for simulation purpose
  void AddToIOQueue(IOQueueItem* item); // adds an item to internal IO queue
private:
  void RaiseIOInterrupt(IOQueueItem* item);
  SortedList<IOQueueItem*> io_queue;
  IORoutines* io_routines;
};

#endif
