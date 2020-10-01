#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include "linear_list.h"

template<class T>
class Single_Linked_list;

template< class T >
class List_single_node {
 friend class Single_Linked_list<T>;
 private:
	T _value;
	List_single_node<T> * _pNext;
	List_single_node<T> * poserror;
};


template< class T >
class Single_Linked_list : public Linear_list<T, List_single_node<T>*>{
 public:
	typedef typename Linear_list<T, List_single_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_single_node<T>*>::position position;

	// costruttori
	Single_Linked_list();
	// costruttore per copia
	Single_Linked_list(const Single_Linked_list<T>& );
	//distruttore
	~Single_Linked_list();

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
	Single_Linked_list<T>& operator=(const Single_Linked_list<T>&); // the assignment operator
	bool operator==(const Single_Linked_list<T> &) const; // tests two list for equality

 private:
	List_single_node<T> * _pHead;
	int _length; // the length of the list
	List_single_node<T> * poserror;
};

template< class T >
Single_Linked_list< T >::Single_Linked_list() {
	_pHead = new List_single_node<T>;
	_pHead->_pNext = _pHead;
	_length = 0;

    poserror = new List_single_node<T>;
    poserror->_pNext = poserror;
    poserror->_value = -1;
}


template< class T >
Single_Linked_list< T >::Single_Linked_list(const Single_Linked_list<T>& L) {
  _length = 0;

	_pHead = new List_single_node<T>;
	_pHead->_pNext = _pHead;

	if (!L.empty()){
		position p = L.begin();
		for (int i=0;i<L.size();i++){
			insert(L.read(p), last());
			p = L.next(p);
		}
	}

    poserror = new List_single_node<T>;
    poserror->_pNext = poserror;
    poserror->_value = -1;
}


template< class T >
Single_Linked_list< T >::~Single_Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class T >
void Single_Linked_list< T >::create(){
	if (empty())
			_length = 0;
}

template< class T >
bool Single_Linked_list< T >::empty() const {
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Single_Linked_list< T >::position
Single_Linked_list< T >::begin() const {
	return (_pHead->_pNext);
}

template< class T >
typename Single_Linked_list< T >::position
Single_Linked_list< T >::last() const {
	position p=begin();
	while (!end(p))
		p=next(p);
	return p;
}


template< class T >
typename Single_Linked_list< T >::position
Single_Linked_list< T >::next(position p) const {
	return(p->_pNext);
}

template< class T >
typename Single_Linked_list< T >::position Single_Linked_list< T >::previous(position p) const {
  position prev=begin();
	while (!end(prev) && next(prev)!=p)
        prev=next(prev);
	return prev;
}

template< class T >
bool Single_Linked_list< T >::end(position p) const {
	return(p == _pHead);
}

template< class T >
typename Single_Linked_list< T >::value_type
Single_Linked_list< T >::read(position p) const {
	if (!end(p))
		return(p->_value);
}

template< class T >
void Single_Linked_list< T >::write(const value_type &a, position p) {
	if (!end(p))
    p->_value = a;
}

template< class T >
void Single_Linked_list< T >::insert(const value_type &a, position p){
	position t = new List_single_node<T>;
	t->_value = a;

	t->_pNext = p;
  position prev=previous(p);
	prev->_pNext = t;

	_length++;
}

template< class T >
void Single_Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		position prev=previous(p);
		prev->_pNext = p->_pNext;
		delete p;
		_length--;
	}
}


template<class T>
typename Single_Linked_list< T >::position Single_Linked_list<T>::intToPos(int pos){
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
int Single_Linked_list<T>::posToInt(position p){
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

template<class T>
Single_Linked_list<T>& Single_Linked_list<T>::operator=(const Single_Linked_list<T>& L){
	if (this != &L){
		_length = 0;

		_pHead = new List_single_node<T>;
		_pHead->_pNext = _pHead;

		if (!L.empty()){
      position p = L.begin();
			for (int i=0;i<L.size();i++) {
				insert(L.read(p), last());
				p = L.next(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Single_Linked_list<T>::operator==(const Single_Linked_list<T> &L) const{
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
void Single_Linked_list<T>::push_front(const value_type &a){
    insert(a,begin());
}

template<class T>
void Single_Linked_list<T>::push_back(const value_type &a){
    insert(a,last());
}

template<class T>
void Single_Linked_list<T>::pop_front(){
    erase(begin());

}

template<class T>
void Single_Linked_list<T>::pop_back(){
   erase(previous(last()));
}

template<class T>
void Single_Linked_list<T>::clear(){
	while(!empty())
		erase(begin());
        _length=0;
}
#endif // _SINGLE_LINKED_LIST_H
