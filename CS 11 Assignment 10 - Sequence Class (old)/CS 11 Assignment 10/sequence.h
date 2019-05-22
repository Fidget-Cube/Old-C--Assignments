//==================================================//
// Max vonBlankenburg, CS 11, Harden, 3/27/18, a9_1 //
//==================================================//
// sequence();
// post: The sequence has been initialized to an empty sequence.

// sequence(const sequence& copyMe);
// post: The sequence has been initialized to a copy of copyMe.

// sequence operator=(const sequence& right);
// post: A copy of right is assigned to the sequence, and the result is returned.

// ~sequence();
// post: The sequence nodes are deleted and all pointers point to NULL.

// void start();
// post: The first item in the sequence becomes the current item (but if the 
// sequence is empty, then there is no current item).

// void advance();
// pre: is_item() returns true
// post: If the current item was already the last item in the sequence, then there 
// is no longer any current item. Otherwise, the new current item is the item immediately after 
// the original current item.

// void insert(const value_type& entry);
// post: A new copy of entry has been inserted in the sequence before the 
// current item. If there was no current item, then the new entry has been inserted at the 
// front. In either case, the new item is now the current item of the sequence.

// void attach(const value_type& entry);
// post: A new copy of entry has been inserted in the sequence after the current 
// item. If there was no current item, then the new entry has been attached to the end of 
// the sequence. In either case, the new item is now the current item of the sequence.

// void remove_current();
// pre: is_item returns true. 
// post: The current item has been removed from the sequence, and the 
// item after this (if there is one) is now the new current item.

// size_type size() const;
// post: Returns the number of items in the sequence.

// bool is_item() const;
// post: A true return value indicates that there is a valid "current" item that
// may be retrieved by the current member function (listed below). A false return value
// indicates that there is no valid current item.

// value_type current() const;
// pre: is_item() returns true
// post: The current item in the sequence is returned.

#ifndef SEQUENCE_H
#define SEQUENCE_H

namespace cs_sequence {
	class sequence {
	public:
		typedef std::size_t size_type;
		typedef double value_type;

		sequence();
		sequence(const sequence& copyMe);
		sequence operator=(const sequence& right);
		~sequence();
		void start();
		void advance();
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();
		size_type size() const;
		bool is_item() const;
		value_type current() const;
	private:
		struct node {
			value_type data;
			node* next;
		};
		size_type numItems;
		node* headPtr;
		node* tailPtr;
		node* cursor;
		node* precursor;
		void copy(const sequence& copyMe);
		void clear();
		void correspondCursors(const sequence& matchMe);
	};
}
#endif
#include "sequence.cpp"