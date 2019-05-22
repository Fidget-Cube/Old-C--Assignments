/*
After any member function is run, root will be pointing to
the top node.*/

#include <iostream>
#include "LL.h"
#include "binarytree.h"
using std::cout;


binarytree::binarytree() {
	root = nullptr;
	mSize = value_type();
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
		root = new binarytree::treenode;
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
	if (root->right == nullptr) {
		int max = root->data;
		binarytree::treenode* tempptr = root;
		root = root->left;
		delete tempptr;
		return max;
	}
	else {
		find_and_remove_max(root->right);
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
	LL<value_type>::iterator i;
	toLL_aux(root, list, i);
	return list;
}





void binarytree::toLL_aux(const treenode* root, LL<value_type>& list, LL<value_type>::iterator& i) {
	if (root != nullptr) {
		toLL_aux(root->right, list, i);
		list.push_front(root->data);
		toLL_aux(root->left, list, i);
		/*                                    example solution, more complex
		toLL_aux(root->left, list, i);
		if (i == nullptr) {
		list.push_front(root->data);
		i = list.begin();
		}
		else {
		list.insert_after(i, root->data);
		}
		toLL_aux(root->right, list, i);
		*/
	}
}