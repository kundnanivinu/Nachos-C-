# Compiler for C++ Program
CC=g++

#CFLAGS= Compiler FLags
# -I for the compiler to look into current directory for the Include files
CFLAGS=-I.

#Depedencies= all the header files in here
DEPS = vikundna_agency.h vikundna_player.h vikundna_team.h

#OBJ= Object files in here
OBJ = vikundna_agency.o vikundna_player.o vikundna_team.o

#OUT: Output to this executable file
OUT = vikundna_agency

#Rule for all the files ending in .o
#Says that the .o files depends on the .c file versions and the .h files included in the DEPS
%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUT): $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) $(OUT)
