#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
// This module represents a family of value-key pairs.

namespace sdds {
	template <class V, class K>
	class Pair {
		K _key;		// Type of the key.
		V _value;	// Type of the value.
	public:
		// Default constructor.
		Pair() :_key{ 0 }, _value{ 0 } {};

		// Copy the values referred to by the parameters into the instance variables.
		Pair(const K& key, const V& value) {
			_key = key;
			_value = value;
		}

		// Returns the value component of the pair.
		const V& value() const {
			return _value;
		}

		// Returns the key component of the pair.
		const K& key() const {
			return _key;
		}

		// Inserts into stream 'os' the key and the value of the pair in the format:
		// KEY : VALUE<endl>
		virtual void display(std::ostream& os) const {
			os << _key << " : " << _value << std::endl;
		}

		// Calls the member 'display()' on 'pair' to insert a pair into stream 'os'.
		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		}
	};
}
#endif
