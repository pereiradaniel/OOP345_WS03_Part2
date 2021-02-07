#ifndef SDDS_SETSUM_H
#define SDDS_SETSUM_H
#include <iostream>
#include "Set.h"

namespace sdds {

	template <unsigned int N, class T, class K, class V>
	class SetSummable : public Set<N, T> {
	
	public:
		// Accumulate into a local object of type 'T' the subset of all the elements in the collection that satisfy 'filter'
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (accumulator.isCompatibleWith(this->get(i))) {
					accumulator += this->get(i);
				}
			}
			return accumulator;

			//T accumulator;
			//accumulator = T::getInitialValue();
			//for (unsigned int i = 0; i < this->size(); i++) {
			//	if (this->get(i) == filter) {
			//		accumulator = this->get(i);
			//	}
			//}
			//return accumulator;
		}
	};
}
#endif