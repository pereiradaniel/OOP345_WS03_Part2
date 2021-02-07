#ifndef SDDS_PAIRSUM_H
#define SDDS_PAIRSUM_H
#include <iostream>
#include <cstring>
#include "Pair.h"

namespace sdds {

	template <class V, class K>
	class PairSummable : public Pair<V, K> {

		static V initial;	// An object of type 'V ' that holds the initial value.
		static size_t minfield;	// Holds the minimum field width for pretty columnar output.

	public:
		// Return initial value.
		static const V& getInitialValue() {
			return initial;
		}

		// Default constructor.
		PairSummable() {
		}

		//  Call the base class constructor passing the two parameters to it.
		// Update the field width if necessary.
		PairSummable(const K& key, const V& value = initial) : Pair <V, K>(key, value) {
			// Determine if field width needs to be updated.
			auto keysize = key.size();
			if (keysize > minfield) {
				minfield = key.size();
			}
		}

		// Return true if the parameter has the same 'key' as the current object, false otherwise.
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			bool result;
			this->key() == b.key() ? result = true : result = false;
			return result;
		}

		// Overload the 'operator+=' to receive a reference to an unmodifiable 'PairSummable' object.
		// This function adds the 'value' of the parameter object to the 'value' of the current object and returns a reference to the current object.
		// Assumes that the current object and the parameter have the same key.
		PairSummable& operator+=(const PairSummable<V, K>& param) {
			if (this->key() == param.key()) {
				PairSummable newpsum(this->key(), this->value() + param.value());
				*this = newpsum;
			}
			return (*this);
		}
		
		 // Override the 'display()' query to set the alighment to left and the field width to the value of the static attribute for all 'K' types, then call the base class version of 'display()' and finally restore the alignment to the right.
		 virtual void display(std::ostream& os) const {
			 os.width(minfield);
			 os << std::left;
			 Pair<V, K>::display(os);
			 os.width(0);
			 os << std::right;
		 }

	};

	template<> std::string PairSummable<std::string, std::string>::initial = "";
	template<> int PairSummable<int, std::string>::initial = 0;
	
	//	PairSummable& operator+=(const PairSummable<V, K>& param) {
	template<> PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& param) {
		if (this->key() == param.key()) {
			if (param.value() == "\0") {
				PairSummable newpsum(this->key(), this->value() + param.value());
				*this = newpsum;
			}
			else {
				PairSummable newpsum(this->key(), this->value() + param.value() + ", ");
				*this = newpsum;
			}

		}
		return (*this);
	}

	template<typename V, typename K>
	size_t PairSummable<V, K>::minfield = 0;

}
#endif