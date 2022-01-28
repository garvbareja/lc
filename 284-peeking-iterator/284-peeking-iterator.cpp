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

class PeekingIterator : public Iterator {
public:
    int next_val=0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    if(Iterator::hasNext()) next_val=Iterator::next();
	}
	
	int peek() {
        return next_val;
	}
    
	int next() {
        int temp=next_val;
        if(Iterator::hasNext()) next_val=Iterator::next();
        else next_val=0;
        return temp;
	}
	
	bool hasNext() const {
	    return next_val;
	}
};