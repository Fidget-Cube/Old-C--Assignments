#include <iostream>

namespace cs_pairs {
	template <class T>
	class OrderedPair {
	public:
		class DuplicateMemberError {};

		typedef T value_type;
		static const value_type DEFAULT_VALUE;

		OrderedPair(value_type newFirst = DEFAULT_VALUE, value_type newSecond = DEFAULT_VALUE);
		void setFirst(value_type newFirst);
		void setSecond(value_type newSecond);
		value_type getFirst() const;
		value_type getSecond() const;
		OrderedPair operator+(const OrderedPair& right) const;
		bool operator<(const OrderedPair& right) const;
		void print() const;
	private:
		value_type first;
		value_type second;
	};


	// Leave the following const declaration commented out when you are testing the non-templated version.
	// Uncomment it when you begin converting to a templated version.

	template <class T>
	const typename OrderedPair<T>::value_type OrderedPair<T>::DEFAULT_VALUE = value_type();

}
#include "orderedpair.cpp"
