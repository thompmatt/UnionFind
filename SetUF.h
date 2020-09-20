/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Set Union Find Header
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
// This header file contains the SetUF class and function definitions. Using
// templates, it constructs SetUF objects of any type, with a value, rank,
// and parent.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef SetUF_H
#define SetUF_H

template <typename> class UnionFind;
template <typename T>

/**
 * The SetUF class represents the concept of a set in the union find data
 * structure. It contains three private member variables, and four member
 * functions to construct the "nodes".
 *
 * @author Matt Thompson
 */
class SetUF {
friend class UnionFind<T>;

private:
	T value; // Value of template, can be anything
	unsigned rank = 0; // Rank value
	SetUF *parent = nullptr; // Parent value

public:
	/**
 	 * Parameterized constructor to set the value of the node
 	 *
 	 * @param v The value of the node, which will be set to the SetUF object
 	 */
	SetUF(T v);

	/**
 	 * Copy constructor which creates a new singleton.
 	 *
 	 * @param &a Value which will be copied to the new singleton.
 	 */
	SetUF(const SetUF &a);

	/**
 	 * Copy assignment operator which creates a new singleton.
 	 *
 	 * @param &a Value which will be copied to the new singleton.
 	 */
	SetUF& operator=(const SetUF &a);

	/**
 	 * Conversion function to implicityly cast SetUF object to a type T.
 	 *
 	 * @return the value of T.
 	 */
	operator T() const { 
		return value;
	}
};

// Definition of functions below:

template <typename T>
SetUF<T> ::SetUF(T value) {
	this->value = value;
	this->rank = 0;
	this->parent = this;
}

template <typename T>
SetUF<T> ::SetUF(const SetUF &a) {
	this->value = a.value;
	this->rank = 0;
	this->parent = this;
}

template <typename T>
SetUF<T>& SetUF<T>::operator=(const SetUF &a) {
	if (this != &a) {
		this->value = a.value;
		this->rank = 0;
		this->parent = this;
	}

	return *this;
}

#endif // SetUF_H