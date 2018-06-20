// io.cc
// Please add your implementation of IORoutines class in this file.

#include "io.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* contents[] = {
  "Perfection is not attainable, but if we chase perfection we can catch excellence.\n",
  "The distance between dreams and reality is called action.\n",
  "A person who never made a mistake never tried anything new.\n"
};

IORoutines::IORoutines(IO* io_interface) {
  io = io_interface;
}

// Please implement this
void
IORoutines::Print(const char* message) {
  IOQueueItem* IOProcess = new IOQueueItem;
  strcpy(IOProcess->kernel_buffer, message);
  IOProcess->operation= PRINT;
  IOProcess->thread= kernel->currentThread;
  io->AddToIOQueue(IOProcess);
  IntStatus newStatus= IntOff;
  IntStatus oldStatus= kernel->interrupt->SetLevel(newStatus);
  kernel->currentThread->Sleep(false);
  newStatus= kernel->interrupt->SetLevel(oldStatus);
}

// Please implement this
void
IORoutines::Read(int message_index, char* buffer) {
  IOQueueItem* IOProcess = new IOQueueItem;
  IOProcess->operation= READ;
  IOProcess->thread= kernel->currentThread;
  IOProcess->user_buffer= buffer;
  IOProcess->message_index = message_index;
  IntStatus newStatus= IntOff;
  IntStatus oldStatus= kernel->interrupt->SetLevel(newStatus);
  io->AddToIOQueue(IOProcess);
  kernel->currentThread->Sleep(false);
  strcpy(buffer, IOProcess->kernel_buffer);
  newStatus= kernel->interrupt->SetLevel(oldStatus);
}

// Please modify this
void
IORoutines::IOInterruptHandler(IOQueueItem* done) {
  switch(done->operation) {
    case PRINT:
	kernel->scheduler->ReadyToRun(done->thread);
      break;
    case READ:
	kernel->scheduler->ReadyToRun(done->thread);
      break;
    default:
      break;
  }
}

static int Compare(IOQueueItem* a, IOQueueItem* b) {
  return a->done_time - b->done_time;
}

IO::IO(): io_queue(Compare) {
  srand(time(NULL));
  io_routines = NULL;
}

void
IO::SimulateIO() {
  while (!io_queue.IsEmpty() 
    && io_queue.Front()->done_time <= kernel->stats->totalTicks) {
    IOQueueItem* ready = io_queue.RemoveFront();
    switch (ready->operation) {
      case PRINT:
        printf("[%d]%s", kernel->stats->totalTicks, ready->kernel_buffer);
        break;
      case READ:
        if ((unsigned)ready->message_index < sizeof(contents) / sizeof(char*)) {
          strcpy(ready->kernel_buffer, contents[ready->message_index]);
        }
        break;
      default:
        break;
    }
    RaiseIOInterrupt(ready);
  }
}

void
IO::SetIORoutines(IORoutines* routines) {
   io_routines = routines; 
}

void
IO::AddToIOQueue(IOQueueItem* item) {
  item->done_time = kernel->stats->totalTicks + rand() % 10000;
  io_queue.Insert(item);
}

void
IO::RaiseIOInterrupt(IOQueueItem* item) {
  if (io_routines == NULL)
    return;
  io_routines->IOInterruptHandler(item);
}
