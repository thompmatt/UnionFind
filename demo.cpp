/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Union Find Demo
// Files: SetUF.h, UnionFind.h, Graph.h, demo.cpp, Makefile, README.md
// Course: CS 368, Spring 2020
//
// Author: Matt Thompson
// Student ID: 9081263262
// Email: mathompson23@wisc.edu
// Lecturer's Name: Marc Renault
//
// Online Sources:
// - https://stackoverflow.com/questions/34945383/use-of-class-template-
//   requires-template-arguments
//
// - https://algorithms.tutorialhorizon.com/disjoint-set-union-find-algorithm
//   -union-by-rank-and-path-compression/
//
//////////////////////////// FILE DESCRIPTION /////////////////////////////////
//
// This file demo's all the functions of UnionFind.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

/**
 * Student class which makes a type "Student" for UnionFind.
 *
 * @author Matt Thompson
 */
class Student {
	/**
	 * Output operator that prints out the ID and name.
	 *
 	 * @return The output stream with the ID and name.
	 */
	friend ostream& operator<<(ostream &strm, const Student &stud) {
		return strm << "student(" << stud.id << ", " << stud.name << ")";
	}

	/**
	 * Boolean operator that compares if IDs are equal.
	 *
 	 * @return true if ID's are equal, otherwise false
	 */
	friend bool operator==(const Student &lhs, const Student &rhs) {
		return lhs.id == rhs.id;
	}

	/**
	 * Boolean operator that compares if IDs are not equal.
	 *
 	 * @return true if ID's are not equal, otherwise false
	 */
	friend bool operator!=(const Student &lhs, const Student &rhs) {
		return !(lhs == rhs);
	}

public:
	Student() = default; // Default constructor
	Student(int id, string name) :
			id(id), name(name) {
	}

private:
	int id;
	string name;
};

/**
 * Animal class which makes a type "Animal" for UnionFind.
 *
 * @author Matt Thompson
 */
class Animal {
	/**
	 * Output operator that prints out the ID and name.
	 *
 	 * @return The output stream with the ID and name.
	 */
	friend ostream& operator<<(ostream &strm, const Animal &anim) {
		return strm << "animal(" << anim.id << ", " << anim.name << ")";
	}

	/**
	 * Boolean operator that compares if IDs are equal.
	 *
 	 * @return true if ID's are equal, otherwise false
	 */
	friend bool operator==(const Animal &lhs, const Animal &rhs) {
		return lhs.id == rhs.id;
	}

	/**
	 * Boolean operator that compares if IDs are not equal.
	 *
 	 * @return true if ID's are not equal, otherwise false
	 */
	friend bool operator!=(const Animal &lhs, const Animal &rhs) {
		return !(lhs == rhs);
	}

public:
	Animal() = default; // Default constructor
	Animal(int id, string name) :
			id(id), name(name) {
	}

private:
	int id;
	string name;
};

/**
 * Car class which makes a type "Car" for UnionFind.
 *
 * @author Matt Thompson
 */
class Car {
	/**
	 * Output operator that prints out the ID and name.
	 *
 	 * @return The output stream with the ID and name.
	 */
	friend ostream& operator<<(ostream &strm, const Car &car) {
		return strm << "car(" << car.id << ", " << car.name << ")";
	}

	/**
	 * Boolean operator that compares if IDs are equal.
	 *
 	 * @return true if ID's are equal, otherwise false
	 */
	friend bool operator==(const Car &lhs, const Car &rhs) {
		return lhs.id == rhs.id;
	}

	/**
	 * Boolean operator that compares if IDs are not equal.
	 *
 	 * @return true if ID's are not equal, otherwise false
	 */
	friend bool operator!=(const Car &lhs, const Car &rhs) {
		return !(lhs == rhs);
	}

public:
	Car() = default; // Default constructor
	Car(int id, string name) :
			id(id), name(name) {
	}

private:
	int id;
	string name;
};

int main() {
	/* 
	 * First example: Student class
	 * Currently represented as:
	 *
	 *		0
	 *	   / \
	 *    1   2
	 *   / \
	 *	4   3
	 */
	cout << "First test: Student" << endl;
	Student marc(0, "Marc");
	Student kyle(1, "Kyle");
	Student hemant(2, "Hemant");
	Student shanmathi(3, "Shanmathi");
	Student kate(4, "Kate");

	std::vector<Student> vertices { marc, kyle, hemant, shanmathi, kate };
	std::vector<Edge<Student> > edges { { marc, kyle }, { marc, hemant }, { kyle,
			shanmathi }, { kyle, kate } };
	Graph<Student> graph(vertices, edges);
	
	// Should not contain a cycle
	if (graph.containsCycle())
		cout << "The graph contains a cycle" << endl;
	else
		cout << "The graph does not contain a cycle" << endl;

	cout << "Adding an edge to the current graph" << endl;
	graph.addEdge({ hemant, shanmathi });

	/*
	 * Now represented as:
	 *		0
	 *	   / \
	 *    1   2
	 *   / \ /
	 *	4   3
	 */

	// Should contain a cycle
	if (graph.containsCycle())
			cout << "The graph contains a cycle\n" << endl;
		else
			cout << "The graph does not contain a cycle\n" << endl;

	/*
	 * Second example: Animal class
	 * Represented as:
	 * 
	 *      0
	 *    /    \
	 *   1      2
	 *    \    /
	 *     3--4
	 */

	cout << "Second test: Animal\n";
	Animal penguin(0, "Penguin");
	Animal dog(1, "Dog");
	Animal cat(2, "Cat");
	Animal kangaroo(3, "Kangaroo");
	Animal giraffe(4, "Giraffe");

	std::vector<Animal> vertices2 { penguin, dog, cat, kangaroo, giraffe };
	std::vector<Edge<Animal> > edges2 { { penguin, dog }, { dog, cat }, { cat,
			kangaroo }, { kangaroo, giraffe }, { giraffe, penguin } };
	Graph<Animal> graph2(vertices2, edges2);

	// Should contain cycle:
	if (graph2.containsCycle()) {
		cout << "The graph contains a cycle\n" << endl;
	} else {
		cout << "The graph does not contain a cycle\n" << endl;
	}

	/*
	 * Third example: Car class
	 * Represented as:
	 * 
	 *      		 0
	 *    		   /   \
	 *   		 1       2
	 *          / \     / \
	 *        3   4    5    6
	 *      / \  / \  / \  /  \
	 *     7  8 9 10 11 12 13 14
	 */

	cout << "Third test: Car\n";
	Car toyota(0, "Toyota");
	Car honda(1, "Honda");
	Car subaru(2, "Subaru");
	Car audi(3, "Audi");
	Car tesla(4, "Tesla");
	Car ford(5, "Ford");
	Car mazda(6, "Mazda");
	Car bmw(7, "BMW");
	Car mercedes(8, "Mercedes");
	Car chrystler(9, "Chrystler");
	Car acura(10, "Acura");
	Car porsche(11, "Porsche");
	Car volvo(12, "Volvo");
	Car volkswagen(13, "Volskwagen");
	Car lexus(14, "Lexus");

	std::vector<Car> vertices3 { toyota, honda, subaru, audi, tesla, ford, mazda, 
		bmw, mercedes, chrystler, acura, porsche, volvo, volkswagen, lexus };

	std::vector<Edge<Car> > edges3 { { toyota, honda }, { toyota, subaru }, { honda, audi }, 
		{ honda, tesla }, { subaru, ford }, { subaru, mazda }, { audi, bmw }, { audi, mercedes }, 
			{ tesla, chrystler }, { tesla, acura }, { ford, porsche }, { ford, volvo }, 
				{ mazda, volkswagen }, { mazda, lexus } };

	Graph<Car> graph3(vertices3, edges3);

	// Should contain cycle:
	if (graph3.containsCycle()) {
		cout << "The graph contains a cycle" << endl;
	} else {
		cout << "The graph does not contain a cycle" << endl;
	}
}
