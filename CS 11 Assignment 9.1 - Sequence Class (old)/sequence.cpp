/*
precursor is NULL when cursor is NULL*/

namespace cs_sequence {
	template <class T>
	Sequence<T>::Sequence() {
		headPtr = nullptr;
		tailPtr = nullptr;
		cursor = nullptr;
		precursor = nullptr;
		numItems = size_type();
	}





	template <class T>
	void Sequence<T>::start() {
		cursor = headPtr;
		precursor = nullptr;
	}





	template <class T>
	void Sequence<T>::advance() {
		if (is_item()) {
			if (cursor == tailPtr) {
				cursor = nullptr;
				precursor = nullptr;
			}
			else {
				precursor = cursor;
				cursor = cursor->next;
			}
		}
	}





	template <class T>
	void Sequence<T>::insert(const value_type& entry) {
		node* new_node = new node;
		new_node->data = entry;
		numItems++;

		if (cursor == headPtr || cursor == nullptr) {
			new_node->next = headPtr;
			headPtr = new_node;
			if (numItems == 1) {
				tailPtr = new_node;
			}
		}
		else {
			new_node->next = cursor;
			precursor->next = new_node;
		}

		cursor = new_node;
	}





	template <class T>
	void Sequence<T>::attach(const value_type& entry) {

	}





	template <class T>
	void Sequence<T>::remove_current() {

	}





	template <class T>
	typename Sequence<T>::size_type Sequence<T>::size() const {
		return numItems;
	}





	template <class T>
	bool Sequence<T>::is_item() const {
		return cursor != nullptr;
	}





	template <class T>
	typename Sequence<T>::value_type Sequence<T>::current() const {
		if (is_item()) {
			return cursor->data;
		}
	}
}