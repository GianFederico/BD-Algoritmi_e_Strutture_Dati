/* A dictionary is a collection of entries of the form (k,v), where k is a key and v is the value
 * associated with the key k (equivalently, v is the value whose key is k).
 */

/* The entry */

#ifndef _DICTIONARY_H
#define _DICTIONARY_H

template<class K, class E>
struct Entry { //In C++ struct is exactly like class except the default accessibility is public for struct (while it's private for class)
  // data member
  K first;
  E second;

  // methods
  Entry(){}
  Entry(Entry<K,E>& e){
    first = e.first;
    second = e.second;
  }
};


template <class K, class E>
class Dictionary
{

public:
  virtual ~Dictionary() {}

  virtual void create() = 0; // create an empty dictionary
  virtual bool empty() const = 0; // return true iff the dictionary is empty
  virtual int size() const = 0;	// return the number of entries in the dictionary
  virtual Entry< K, E>* find(const K& k) const = 0; // return the entry with key k
  virtual void insert(Entry< K, E>& e) = 0; // insert the entry e into the dictionary
  virtual void erase(const K& k) = 0;	// delete the entry with key k
  virtual void modify(const K& k, const E& e) = 0; // modify the value of the entry with key k to e
};

#endif
