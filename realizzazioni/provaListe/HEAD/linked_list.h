#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"

template<class T>
class Linked_list;

template< class T >
class List_node{
	friend class Linked_list<T>;
 private:
	T _value;
	List_node<T> * _pPrev;
	List_node<T> * _pNext;
};


template< class T >
class Linked_list : public Linear_list<T, List_node<T>*>{
 public:
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_node<T>*>::position position;

	// costruttori
	Linked_list();
	Linked_list(int);
	// costruttore per copia
	Linked_list(const Linked_list<T>& );
	//distruttore
	~Linked_list();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);
	int size() const {
		return _length;
	};
	void push_front(const value_type &);
	void push_back(const value_type &);
	void pop_front();
	void pop_back();
	void clear();
    position intToPos(int pos);
	int posToInt(position p);



	// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
	bool operator==(const Linked_list<T> &) const; // tests two list for equality

 private:
	List_node<T> * _pHead;
	int _length; // the length of the list
	List_node<T> * poserror;
};

template< class T >
Linked_list< T >::Linked_list() {
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;

	poserror = new List_node<T>;
    poserror->_pNext = poserror;
    poserror->_pPrev = poserror;
    poserror->_value = -1;
}


template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) {
  _length = L.size();

	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

	if (!L.empty()){
		position p = L.last();
		for (int i=0; i <= L._length; i++){
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}

    poserror = new List_node<T>;
    poserror->_pNext = poserror;
    poserror->_pPrev = poserror;
    poserror->_value = -1;
}


template< class T >
Linked_list< T >::~Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
	_length--;
}

template< class T >
void Linked_list< T >::create(){
	if (empty())
        _length = 0;
}

template< class T >
bool Linked_list< T >::empty() const {
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position
Linked_list< T >::begin() const {
	return (_pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position
Linked_list< T >::last() const {
	return (_pHead->_pPrev);
}


template< class T >
typename Linked_list< T >::position
Linked_list< T >::next(position p) const {
	return(p->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const {
	if (p != _pHead)
		return(p->_pPrev);
}

template< class T >
bool Linked_list< T >::end(position p) const {
	return(p == _pHead);
}

template< class T >
typename Linked_list< T >::value_type
Linked_list< T >::read(position p) const {
	if (!end(p))
		return(p->_value);
}

template< class T >
void Linked_list< T >::write(const value_type &a, position p) {
	if (!end(p))
    p->_value = a;
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p){
	position t = new List_node<T>;
	t->_value = a;

	t->_pNext = p;
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
}

template< class T >
void Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
		_length--;
	}
}


template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
	if (this != &L){
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
	if (L.size() != _length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}

template<class T>
void Linked_list<T>::push_front(const value_type &a){
    insert(a,begin());
}

template<class T>
void Linked_list<T>::push_back(const value_type &a){
    insert(a,next(last()));
}

template<class T>
void Linked_list<T>::pop_front(){
    erase(begin());
}

template<class T>
void Linked_list<T>::pop_back(){
    erase(last());
}

template<class T>
void Linked_list<T>::clear(){
	while(!empty())
		erase(begin());
            _length=0;
}

template<class T>
typename Linked_list< T >::position Linked_list<T>::intToPos(int pos){
    position p = begin();
    if(!end(p) && pos<=_length)
        for (int i=0; i<pos-1; i++)
            if (!end(p->_pNext))
                p = p->_pNext;

    if(p==begin() && pos!=1)
        p = poserror;
    return (p);
}

template<class T>
int Linked_list<T>::posToInt(position p){
    if (!empty()){
        int i = 0;
        position a;
        a = begin();
        if (a == p)
            return 1;
        while (a->_pNext != p){
            i++;
            a = a->_pNext;
        }
        i++;
        return (i);
        }
    return 0;
}

#endif // _LINKED_LIST_H
