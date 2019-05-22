//==================================================//
// Max vonBlankenburg, CS 11, Harden, 3/27/18, a9_1 //
//==================================================//

#ifndef SEQUENCE_H
#define SEQUENCE_H

namespace cs_sequence {
	template <class T>
	class Sequence {
	public:
		typedef T value_type;
		typedef size_t size_type;

		Sequence();
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
	};
}
#endif
#include "sequence.cpp"