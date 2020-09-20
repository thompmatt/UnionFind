/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Graph Header
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
// This header file contains the Graph class and function definitions.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <utility>
#include "UnionFind.h"

template<typename T> using Edge = std::pair<T, T>;

template<typename T>

/**
 * The Graph class uses the union find data structure to detect whether it
 * has a cycle or not.
 *
 * @author Matt Thompson
 */
class Graph {
	using Edge = std::pair<T, T>; // Creates a pair of nodes

private:
	std::vector<T> vertices; // Vector of nodes (which will be the sets)
	std::vector<Edge> edges; // Vector of edges

public:
	/**
 	 * Parameterized constructor that assigns the vertices and egdes vectors.
 	 *
 	 * @param v Vector to be assigned to vertices
 	 * @param e Vector to be assigned to edges
 	 */
	Graph(std::vector<T> v, std::vector<Edge> e) :
			vertices(v), edges(e) {
	}

	/**
 	 * Function that adds an Edge to the edges vector.
 	 *
 	 * @param e Edge to be added to the vector.
 	 */
	void addEdge(Edge e) {
		edges.push_back(e);
	};

	/**
 	 * Function that returns whether the Graph contains a cycle or not. The
 	 * function constructs a UnionFind data structure and iterates through the 
 	 * edges vector, comaparing sets. If the roots match, then there is a cycle.
	 * Otherwise, if at the end of the for loop iterations there was no sets whose
	 * roots matched, it returns false.
 	 *
 	 * @return true if it has a cycle, false otherwise.
 	 */
	bool containsCycle();
};

template<typename T>
bool Graph<T>::containsCycle() {
	UnionFind<T> uFind(vertices); // Constructs Union Find

	// Iterates through all the elements in edges vector
	for (Edge &e : edges) {
		SetUF<T> &xRoot = uFind.find(e.first);
		SetUF<T> &yRoot = uFind.find(e.second);

		if (xRoot == yRoot) {
			return true;
		}

		uFind.unionOp(xRoot, yRoot); 
	}
	return false;
}

#endif
