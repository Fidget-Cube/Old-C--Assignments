/*
first is always empty when first.top() is NULL*/
#include <cassert>

namespace cs_sequence {
	sequence::sequence() {}





	void sequence::start() {
		if (first.empty() && !second.empty()) {
			first.push(second.top());
			second.pop();
		} 
		else {
			while (first.size() > 1) {
				second.push(first.top());
				first.pop();
			}
		}
	}





	void sequence::advance() {
		assert(is_item());
		if (second.empty()) {
			while (is_item()) {
				second.push(first.top());
				first.pop();
			}
		} 
		else {
			first.push(second.top());
			second.pop();
		}
	}




	
	void sequence::insert(const value_type& entry) {
		if (is_item()) {
			second.push(first.top());
			first.pop();
		}
		first.push(entry);
	}




	
	void sequence::attach(const value_type& entry) {
		if (first.empty()) {
			while (!second.empty()) {
				first.push(second.top());
				second.pop();
			}
		}
		first.push(entry);
	}





	void sequence::remove_current() {
		assert(is_item());
		first.pop();
		if (second.empty()) {
			while (is_item()) {
				second.push(first.top());
				first.pop();
			}
		}
		else {
			first.push(second.top());
			second.pop();
		}
	}





	typename sequence::size_type sequence::size() const {
		return first.size() + second.size();
	}





	bool sequence::is_item() const {
		return !first.empty();
	}





	typename sequence::value_type sequence::current() const {
		assert(is_item());
		return first.top();
	}
}