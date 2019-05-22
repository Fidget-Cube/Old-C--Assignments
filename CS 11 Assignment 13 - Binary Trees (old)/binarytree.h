//===========================================================================//
// Max vonBlankenburg, 4/24/18, Harden, CS 11, binarytree.h & binarytree.cpp //
//===========================================================================//

// binarytree();
// post: Root and mSize are initialized to null and the default value of
//       value_type.

// void insert(value_type item);
// post: The data in item is inserted into the binary tree.

// void print() const;
// post: The contents of the binary tree are printed onto the screen.

// size_type size() const;
// post: The function returns mSize.

// value_type find(value_type target, bool& found) const;
// post: If target is in the binary tree, found is set to true and the
//       function returns the data that matches target. Otherwise, found
//       is set to false and the function returns the default value of
//       value_type.

// void del(value_type target, bool& found);
// post: If target is in the binary tree, found is set to true and the data
//       that matches target is deleted. Otherwise, found is set to false.

// size_type numPrimes() const;
// post: The function returns the number of prime numbers there are in the
//       binary tree.

// LL<value_type> toLL() const;
// post: The function returns an LL object with the items in the calling
//       binary tree in ascending order.

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>	// for size_t
#include "LL.h"    // for toLL()

class binarytree {

public:
	typedef std::size_t size_type;
	typedef int value_type;

	binarytree();
	void insert(value_type item);
	void print() const;
	size_type size() const;
	value_type find(value_type target, bool& found) const;
	void del(value_type target, bool& found);
	size_type numPrimes() const;
	LL<value_type> toLL() const;
private:
	struct treenode {
		value_type data;
		treenode* left;
		treenode* right;
	};
	treenode* root;
	size_type mSize;

	static void insert_aux(treenode*& root, size_type& mSize, value_type item);
	static void print_aux(const treenode* root);
	static value_type find_aux(const treenode* root, value_type target, bool& found);
	static void del_aux(treenode*& root, size_type& mSize, value_type target, bool& found);
	static value_type find_and_remove_max(treenode*& root);
	static size_type numPrimes_aux(const treenode* root);
	static bool isPrime(value_type num);
	static void toLL_aux(const treenode* root, LL<value_type>& list, LL<value_type>::iterator& i);
};
#endif