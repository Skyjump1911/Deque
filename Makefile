#
# @file Makefile
# @author Noah Melton and Sam Toney
# @date 2025-04-23
# @brief Makefile for deque program
#
# Used to automate compiling and cleaning up unwanted files.
#

CXX = g++

CXXFLAGS = -Wall -Wextra -g

all: program

program: main.o deque.o
	$(CXX) $(CXXFLAGS) -o program main.o deque.o
main.o: main.cpp deque.h
	$(CXX) $(CXXFLAGS) -c main.cpp
deque.o: deque.cpp deque.h
	$(CXX) $(CXXFLAGS) -c deque.cpp
clean:
	rm -f *.o *~ program
