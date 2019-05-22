/*
Precursor is NULL when cursor is NULL.

The copy() function changes the data in the sequence to match that of copyMe.

The clear() function deletes all nodes in the sequence and sets the pointers to nullptr.

The correspondCursors() function finds the location of the cursor in matchMe,
then sets cursor and precursor to their corresponding locations in the sequence
to match the cursor and precursor of matchMe. (unused, found better solution)*/
#include <cassert>

namespace cs_sequence {
	sequence::sequence() {
		headPtr = nullptr;
		tailPtr = nullptr;
		cursor = nullptr;
		precursor = nullptr;
		numItems = size_type();
	}





	sequence::sequence(const sequence& copyMe) {
		copy(copyMe);
	}





	sequence sequence::operator=(const sequence& right) {
		if (this != &right) {
			clear();
			copy(right);
		}
		return *this;
	}





	sequence::~sequence() {
		clear();
	}





	void sequence::start() {
		cursor = headPtr;
		precursor = nullptr;
	}





	void sequence::advance() {
		assert(is_item());
		if (cursor == tailPtr) {
			cursor = nullptr;
			precursor = nullptr;
		} else {
			precursor = cursor;
			cursor = cursor->next;
		}
	}




	
	void sequence::insert(const value_type& entry) {
		node* newNode = new node;
		newNode->data = entry;
		numItems++;

		if (cursor == headPtr || cursor == nullptr) {
			newNode->next = headPtr;
			headPtr = newNode;
			if (numItems == 1) {
				tailPtr = newNode;
			}
		} else {
			newNode->next = cursor;
			precursor->next = newNode;
		}

		cursor = newNode;
	}





	void sequence::attach(const value_type& entry) {
		node* newNode = new node;
		newNode->data = entry;
		numItems++;

		if (cursor == tailPtr || cursor == nullptr) {
			if (numItems == 1)
				headPtr = newNode;
			else
				tailPtr->next = newNode;
			precursor = tailPtr;
			tailPtr = newNode;
			newNode->next = nullptr;
		} else {
			newNode->next = cursor->next;
			cursor->next = newNode;
			precursor = cursor;
		}

		cursor = newNode;
	}





	void sequence::remove_current() {
		assert(is_item());
		numItems--;

		if (cursor == tailPtr)
			tailPtr = precursor;
		if (cursor == headPtr) {
			headPtr = headPtr->next;
			delete cursor;
			cursor = headPtr;
		} else {
			precursor->next = precursor->next->next;
			delete cursor;
			cursor = precursor->next;
		}
	}





	typename sequence::size_type sequence::size() const {
		return numItems;
	}





	bool sequence::is_item() const {
		return cursor != nullptr;
	}





	typename sequence::value_type sequence::current() const {
		assert(is_item());
		return cursor->data;
	}





	void sequence::copy(const sequence& copyMe) {
		cursor = nullptr;
		precursor = nullptr;

		if (copyMe.numItems == 0) {
			headPtr = nullptr;
			tailPtr = nullptr;
		} else {
			headPtr = new node;
			headPtr->data = copyMe.headPtr->data;
			tailPtr = headPtr;
			if (copyMe.cursor == copyMe.headPtr)
				cursor = headPtr;
			else if (copyMe.precursor == copyMe.headPtr)
				precursor = headPtr;

			node* sourcePtr = copyMe.headPtr->next;
			while (sourcePtr != nullptr) {
				tailPtr->next = new node;
				tailPtr = tailPtr->next;
				tailPtr->data = sourcePtr->data;
				if (copyMe.cursor == sourcePtr)
					cursor = tailPtr;
				else if (copyMe.precursor == sourcePtr)
					precursor = tailPtr;
				sourcePtr = sourcePtr->next;
			}
			tailPtr->next = nullptr;
		}
		numItems = copyMe.numItems;
	}





	void sequence::clear() {
		cursor = headPtr;
		precursor = nullptr;
		while (cursor != nullptr) {
			headPtr = cursor->next;
			delete cursor;
			cursor = headPtr;
		}
		tailPtr = nullptr;
		numItems = 0;
	}





	void sequence::correspondCursors(const sequence& matchMe) {
		size_type count = 0;
		node* finder = matchMe.headPtr;
		while (finder != nullptr && finder != matchMe.cursor) {
			count++;
			finder = finder->next;
		}

		finder = headPtr;
		precursor = nullptr;
		while (finder != nullptr && count > 0) {
			if (count == 1 && finder->next != nullptr)
				precursor = finder;
			count--;
			finder = finder->next;
		}
		cursor = finder;
	}
}