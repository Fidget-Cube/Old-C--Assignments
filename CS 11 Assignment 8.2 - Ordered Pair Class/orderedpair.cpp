/* The values of first and second cannot be equal,
except when they are both equal to DEFAULT_VALUE.
*/
#include <iostream>

namespace cs_pairs {
	template <class T>
	OrderedPair<T>::OrderedPair(value_type newFirst, value_type newSecond) {
		setFirst(newFirst);
		setSecond(newSecond);
	}





	template <class T>
	void OrderedPair<T>::setFirst(value_type newFirst) {
		if (newFirst == second && newFirst != DEFAULT_VALUE)
			throw DuplicateMemberError();
		first = newFirst;
	}





	template <class T>
	void OrderedPair<T>::setSecond(value_type newSecond) {
		if (newSecond == first && newSecond != DEFAULT_VALUE)
			throw DuplicateMemberError();
		second = newSecond;
	}





	template <class T>
	typename OrderedPair<T>::value_type OrderedPair<T>::getFirst() const {
		return first;
	}





	template <class T>
	typename OrderedPair<T>::value_type OrderedPair<T>::getSecond() const {
		return second;
	}





	template <class T>
	OrderedPair<T> OrderedPair<T>::operator+(const OrderedPair<T>& right) const {
		return OrderedPair<T>(first + right.first, second + right.second);
	}





	template <class T>
	bool OrderedPair<T>::operator<(const OrderedPair<T>& right) const {
		return first + second < right.first + right.second;
	}





	template <class T>
	void OrderedPair<T>::print() const {
		cout << "(" << first << ", " << second << ")";
	}
}