#################################################################
#
#  Makefile for Binary Heap programs: CS 4122/5122
#
#  Files:
#  heaptester.cpp   Program for testing the binary heap
#  sorttester.cpp   Program for testing sorting algorithms
#
#  binheap.h        The header file for the Binary Heap class
#  binheap.cpp      The implemention file for the Binary Heap class
#
#  heaptester       Executable for testing heap
#  sorttester       Executable for timing and testing sorts
#
##################################################################

CC = g++ 
DEBUG = 

CFLAGS = $(DEBUG) -c

TARGETS = heaptester sorttester

all: $(TARGETS)


# Link the object files:
heaptester: heaptester.o binheap.o
	$(CC) -o $@ heaptester.o binheap.o

sorttester: sorttester.o binheap.o quicksort.o
	$(CC) -o $@ sorttester.o binheap.o quicksort.o


# Compile the C++ files into object files
heaptester.o: heaptester.cpp binheap.h
	$(CC) $(CFLAGS) heaptester.cpp 

sorttester.o: sorttester.cpp binheap.h quicksort.h
	$(CC) $(CFLAGS) sorttester.cpp 

binheap.o: binheap.cpp binheap.h
	$(CC) $(CFLAGS) binheap.cpp 

quicksort.o: quicksort.cpp quicksort.h
	$(CC) $(CFLAGS) quicksort.cpp 

# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f $(TARGETS)
