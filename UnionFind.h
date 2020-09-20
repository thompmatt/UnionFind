/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Union Find Header
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
// This header file contains the UnionFind class and function definitions. Along
// with the SetUF class, it has a vector sets full of singletons. It also
// contains basic methods like find() using path compression and union operators.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef UnionFind_H
#define UnionFind_H

#include "SetUF.h"
#include <vector>

template <typename T>

/**
 * The UnionFind class represents a disjoint set data structure. It contains
 * one private field and five member functions.
 *
 * @author Matt Thompson
 */
class UnionFind {
private:
	std::vector<SetUF<T> > sets; // Vector which contains all SetUF "nodes"

public:
	/**
 	 * Parameterized constructor to add the singletons to the container sets.
 	 *
 	 * @param &singletons A vector with the singletons to be added to the new
 	 *   				  vector "sets".
 	 */
	UnionFind(const std::vector<T> &singletons);

	/**
 	 * Function that finds the root of the set to which the node belongs to.
 	 * Utilizes path compression.
 	 *
 	 * @param T The node whose root will be found.
 	 * @return The root of the set.
 	 */
	SetUF<T>& find(T node);

	/**
 	 * Union function compares both sets by rank. Using the root of both sets
 	 * one is made the parent of the other and the rank is adjusted accordingly.
 	 *
 	 * @param &x First set to compare.
 	 * @param &y Second set to compare.
 	 */
	void unionOp(SetUF<T> &x, SetUF<T> &y);

	/**
 	 * Union function that calls the find() method on the first node, and then
 	 * calls the unionOp() function that compares both sets.
 	 *
 	 * @param x Node that will be converted to a set, using find().
 	 * @param &y Second set to compare.
 	 */
	void unionOp(T x, SetUF<T> &y);

	/**
 	 * Union function that calls the find() method on the second node, and then
 	 * calls the unionOp() function that compares both sets.
 	 *
 	 * @param &x First set to compare.
 	 * @param y Node that will be converted to a set, using find().
 	 */
	void unionOp(SetUF<T> &x, T y);

	/**
 	 * Union function that calls the find() method on both nodes, and then
 	 * calls the unionOp() function that compares both sets.
 	 *
 	 * @param x First node that will be converted to a set, using find().
 	 * @param y Second node that will be converted to a set, using find().
 	 */
	void unionOp(T x, T y);
};

// Definition of the functions
template <typename T>
UnionFind<T> ::UnionFind(const std::vector<T> &singletons) {
	for (int i = 0; i < singletons.size(); i++) {
		this->sets.push_back(singletons.at(i));
	}
}

template <typename T>
SetUF<T>& UnionFind<T>::find(T node) {
	// Iterates through sets, until node matches
	for (int i = 0; i < sets.size(); i++) {
		if (node == sets.at(i)) {
			SetUF<T> * curr = &sets.at(i);
			std::vector<SetUF<T> > nodes;

			// Finds the root
			while (curr->parent != curr) {
				nodes.push_back(*curr);
				curr = curr->parent;
			}

			// Path compression
			for (int i = 0; i < nodes.size(); i++) {
				nodes.at(i).parent = curr;
			}

			return *curr;
		}
	}
}

template <typename T>
void UnionFind<T> ::unionOp(SetUF<T> &x, SetUF<T> &y) {
	if (x.rank == y.rank) {
		y.parent = &x;
		x.rank++;
	} else if (x.rank > y.rank) {
		y.parent = &x;
	} else {
		x.parent = &y;
	}
}

template <typename T>
void UnionFind<T> ::unionOp(T x, SetUF<T> &y) {
	SetUF<T>& curr_x = find(x);

	unionOp(curr_x, &y);
}

template <typename T>
void UnionFind<T> ::unionOp(SetUF<T> &x, T y) {
	SetUF<T>& curr_y = find(y);

	unionOp(&x, curr_y);
}

template <typename T>
void UnionFind<T> ::unionOp(T x, T y) {
	SetUF<T>& curr_x = find(x);
	SetUF<T>& curr_y = find(y);

	unionOp(curr_x, curr_y);
}


#endif // UnionFind_H