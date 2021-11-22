/************************************************
Problem: 		284. Peeking Iterator
Algorithm: 		Design
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

// Solution 1:

class PeekingIterator : public Iterator {
public:
    
    Iterator *it;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    it = new Iterator(nums);
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        Iterator tmp(*it);
        return tmp.next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return it->next();
	}
	
	bool hasNext() const {
	    return it->hasNext();
	}
};

// Solution 2: better way to benefit from inherit constructor

class PeekingIterator : public Iterator {
public:
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return Iterator::next();
	}
	
	bool hasNext() const {
	    return Iterator::hasNext();
	}
};