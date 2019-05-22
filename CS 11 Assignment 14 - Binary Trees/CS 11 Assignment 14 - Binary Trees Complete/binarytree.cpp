/*
After any member function is run, root will be pointing to
the top node.*/

#include <iostream>
#include <cassert>
#include "LL.h"
#include "binarytree.h"
using std::cout;


binarytree::binarytree() {
	root = nullptr;
	mSize = value_type();
}





binarytree::binarytree(const binarytree& copyMe) {
	copy(root, mSize, copyMe.root);
}





// need function to check if two trees are the same
binarytree binarytree::operator=(const binarytree& copyMe) {
	clear(root, mSize);
	copy(root, mSize, copyMe.root);
	return *this;
}





binarytree::~binarytree() {
	clear(root, mSize);
}





// pre: Binary tree to be copied to is empty (rootLeft == nullptr && sizeLeft == 0).
// post: A deep copy of the right binary tree (rootRight) is done on the left binary tree.
void binarytree::copy(treenode*& rootLeft, size_type& sizeLeft, const treenode* rootRight) {
	if (rootRight != nullptr) {
		rootLeft = new treenode;
		rootLeft->data = rootRight->data;
		rootLeft->left = nullptr;
		rootLeft->right = nullptr;
		sizeLeft++;
		copy(rootLeft->left, sizeLeft, rootRight->left);
		copy(rootLeft->right, sizeLeft, rootRight->right);
	}
}





// post: All the data in the binary tree is cleared
void binarytree::clear(treenode*& root, size_type& mSize) {
	if (root != nullptr) {
		if (root->left != nullptr) {
			clear(root->left, mSize);
		}
		if (root->right != nullptr) {
			clear(root->right, mSize);
		}
		delete root;
		root = nullptr;
		mSize--;
	}
}





void binarytree::print() const {
	print_aux(root);
}





void binarytree::print_aux(const treenode* root) {
	if (root != nullptr) {
		print_aux(root->left);
		cout << root->data << " ";
		print_aux(root->right);
	}
}





void binarytree::insert(value_type item) {
	insert_aux(root, mSize, item);
}





void binarytree::insert_aux(treenode*& root, size_type& mSize, value_type item) {
	if (root == nullptr) {
		root = new treenode;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;
		mSize++;
	}
	else if (item <= root->data) {
		insert_aux(root->left, mSize, item);
	}
	else {
		insert_aux(root->right, mSize, item);
	}
}





binarytree::size_type binarytree::size() const {
	return mSize;
}





binarytree::value_type binarytree::find(value_type target, bool& found) const {
	return find_aux(root, target, found);
}





binarytree::value_type binarytree::find_aux(const treenode* root,
	value_type target,
	bool& found) {

	if (root == nullptr) {
		found = false;
		return value_type();
	}
	else if (target == root->data) {
		found = true;
		return root->data;
	}
	else if (target < root->data) {
		return find_aux(root->left, target, found);
	}
	else {
		return find_aux(root->right, target, found);
	}
}





void binarytree::del(value_type target, bool& found) {
	del_aux(root, mSize, target, found);
}





void binarytree::del_aux(binarytree::treenode*& root,
	size_type& mSize,
	value_type target,
	bool& found) {

	if (root == nullptr) {
		found = false;
	}
	else if (target < root->data) {
		del_aux(root->left, mSize, target, found);
	}
	else if (target > root->data) {
		del_aux(root->right, mSize, target, found);
	}
	else if (root->left == nullptr) {
		binarytree::treenode* tempptr = root;
		root = root->right;
		delete tempptr;
		mSize--;
		found = true;
	}
	else {
		root->data = find_and_remove_max(root->left);
		mSize--;
		found = true;
	}
}





// pre: root != nullptr
// post: If a maximum value is found in the tree, the node is deleted and the value is returned.
//       Otherwise, the function calls itself.
binarytree::value_type binarytree::find_and_remove_max(binarytree::treenode*& root) {
	assert(root != nullptr);
	if (root->right == nullptr) {
		int max = root->data;
		binarytree::treenode* tempptr = root;
		root = root->left;
		delete tempptr;
		return max;
	}
	else {
		return find_and_remove_max(root->right);
	}
}





binarytree::size_type binarytree::numPrimes() const {
	return numPrimes_aux(root);
}





binarytree::size_type binarytree::numPrimes_aux(const treenode* root) {
	if (root == nullptr) {
		return size_type();
	}
	else if (isPrime(root->data)) {
		return numPrimes_aux(root->left) + numPrimes_aux(root->right) + 1;
	}
	else {
		return numPrimes_aux(root->left) + numPrimes_aux(root->right);
	}
}





// post: If num is a prime number, the function returns true.
//       Otherwise, it returns false.
bool binarytree::isPrime(binarytree::value_type num) {
	if (num < 2) {
		return false;
	}
	else {
		for (int i = 2; i <= (num / 2); i++) {
			if ((num % i) == 0) {
				return false;
			}
		}
		return true;
	}
}





LL<binarytree::value_type> binarytree::toLL() const {
	LL<value_type> list;
	toLL_aux(root, list);
	return list;
}





void binarytree::toLL_aux(const treenode* root, LL<value_type>& list) {
	if (root != nullptr) {
		toLL_aux(root->right, list);
		list.push_front(root->data);
		toLL_aux(root->left, list);
	}
}