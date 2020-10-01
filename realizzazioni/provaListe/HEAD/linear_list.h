#ifndef _LISTALIN_H
#define _LISTALIN_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template< class T, class P >
class Linear_list{
 public:
	typedef T value_type;   // the type of object, T, stored in the list
	typedef P position;

	// operators
	virtual void create() = 0;
	virtual bool empty() const = 0; // true if the list's size is 0
	virtual value_type read(position) const = 0;
	virtual void write(const value_type & x, position p) = 0; // write x at position p
	virtual position begin() const = 0;  // returns a position pointing to the beginning of the list
	virtual bool end(position) const = 0; // true with a position pointing to the end of the list
	virtual position next(position) const = 0; // returns the next position
	virtual position previous(position) const = 0; // return the previous position
	virtual void insert(const value_type &, position) = 0; // insert an element
	virtual void erase(position pos) = 0; // ersaes the element at position pos

	virtual int size() const = 0;  // returns the size of the list
    virtual void push_front(const value_type &) = 0; // insert a new element at the beginning
    virtual void push_back(const value_type &) = 0; // insert a new element at the end
    virtual void pop_front() = 0; // removes the first element
    virtual void pop_back() = 0; // removes the last element
    virtual void clear() = 0; // erases all the elements

};

/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore <<
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
	typename Linear_list<T,P>::position p;
	p = l.begin();
	os << "[";
	while (!l.end(p)){
		if (p != l.begin())
			os << ", " << l.read(p);
		else
			os << l.read(p);
		p = l.next(p);
	}
	os << "]" << endl;
	return os;
}


#endif // _LISTALIN_H

