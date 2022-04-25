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
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        m_has_next = Iterator::hasNext();
	    if (m_has_next) 
            m_next = Iterator::next();
	}
	
	int peek() {
        return m_next;
	}
	
	int next() {
	    int temp = m_next;
        m_has_next = Iterator::hasNext();
        if (m_has_next) m_next = Iterator::next();
        return temp;
	}
	
	bool hasNext() const {
	    return m_has_next;
	}
    
private:
    int m_next;
    bool m_has_next;
};