#////////////////////////////// FILE HEADER ///////////////////////////////////
#/
#/ Title: Union Find Makefile
#/ Files: Point.h, Ship.h, Board.h, Battleship.h, Battleship.cpp, Makefile, README.md
#/ Course: CS 368, Spring 2020
#/
#/ Author: Matt Thompson
#/ Student ID: 9081263262
#/ Email: mathompson23@wisc.edu
#/ Lecturer's Name: Marc Renault
#/
#/ Online Sources: NONE
#/
#/////////////////////////// FILE DESCRIPTION /////////////////////////////////
#/
#/ This is the makefile for demo.cpp, which displays the Union Find program.
#/
#//////////////////////////////////////////////////////////////////////////////

# Makefile

CXX=g++ -std=c++11
CXXFLAGS=-Wall

all: build

clean:
	-rm demo

build: demo.cpp
	$(CXX) $(CXXFLAGS) -o demo demo.cpp