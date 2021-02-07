#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template <unsigned int N, class T>
	class Set {
		T result[N];			// The type of any element in the collection.
		unsigned elements = 0;	// Initially the collection has no elements.
	public:
		// Return the current number of elements in the collection.
		size_t size() const {
			return elements;
		}

		// Return a reference to the element at index 'idx' of the statically allocated array.
		// Assume that the parameter is valid.
		const T& get(size_t idx) const {
			return result[idx] ;
		}

		// If the collection has capacity for another element, add a copy of 'item' to the collection.
		// Otherwise, does nothing.
		void operator+=(const T& item) {
			if (elements < N) {
				result[elements] = item;	// Add item to results.
				elements++;					// Increment number of elements.
			}
		}
	};
}
#endif