#ifndef HASH_TABLE_H
#define HASH_TABLE_H
/***************************************************************************
 *   Copyright (C) 2005 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "dictionary.h"

/* A possibility for the representation of a dictionary is to use hashing.
 *
 * This method use a hash function to map dictionary entries into positions in a table
 * called the hash table.
 *
 * In the ideal situation, if entry e has the key k and f is the hash function, the entry e
 * is stored in position f(k) of the table.
 *
 * Assume for now that each position of the table can store at most one entry. To search for
 * an entry with key k, we compute f(k) and see whether an entry exists at position f(k) of the table.
 * If so, we have found the desired entry. If not, the dictionary contains no entry with the
 * specified key k. In the former case the entry may be deleted (if desired) by making position
 * f(k) of the table empty. In the latter case the entry may be added by placing it in position
 * f(k).
 *
 * In the ideal situation just described, it takes O(b) time to initialize an empty dictionary
 * (b is the number of positions in the hash table) and O(1) time to perform a find, insert or
 * erase operation.
 *
 * When the key range is too large, we use a hash table that has a number of positions that is
 * smaller than the key range and a hash function f(k) that maps several different keys into the
 * same position of the hash table. Each position of the table is a _bucket_; f(k) is the
 * _home bucket_ for the entry whose key is k; and the number of buckets in a table equals the
 * table length.
 *
 * Since a hash function may map several keys into the same bucket, we may consider designing
 * buckets that can hold more than one entry.
 *
 * Of the many hash functions that have been proposed, hashing by division is most common.
 * In hashing by division, the hash function has the form f(k) = k % D, where k is the key,
 * D is the length (number of buckets) of the hash table.
 *
 * A collision occurs whenever two different keys have the same home bucket.
 *
 * = DELETION =
 *
 * The deletion of an entry must leave behind a table on which the search method works correctly.
 *
 * A deletion may require us to move several entries. The search for entries to move begins just after
 * the bucket vacated by the deleted entry and proceeds to successive buckets until 1) we either
 * reach an empty bucket or 2) we return to the bucket from which the deletion took place.
 *
 * When entries are moved up the table following a deletion, we must take care not to move an entry
 * to a position before its home bucket because making such an entry move would cause the search
 * for this entry to fail.
 *
 * An alternative to this method is to introduce the field never_used in each bucket. When the
 * table is initialized, this field is set to true for all buckets. When an entry is placed into a
 * bucket, its never_used field is set to false. Now condition (2) for search termination is
 * replaced by: a bucket with its never_used field equal to true is reached.
 *
 * We accomplish a removal by setting the table position occupied by the removed entry to NULL.
 * A new entry may be inserted into the first empty bucket encountered during a search that
 * begins at the entry's home bucket.
 *
 * Notice that in this alternative scheme, never_used is never reset to true. After a while all
 * buckets have this field equal to false, and unsuccessful searches examines all buckets.
 *
 * To improve performance, we must reorganize the table when many empty buckets have their
 * never_used field equal to false. This reorganization could, for example, involve reinserting
 * all remaining entries into an empty hash table.
 */

#include <string>
#include <iostream>

using std::string;

template<class T>
class Hash{
public:
  size_t operator()(const T the_key) const;
};

/*

size_t: Unsigned integral type. Alias of one of the fundamental unsigned integer types.
        It is a type able to represent the size of any object in bytes: size_t is the type
        returned by the sizeof operator and is widely used in the standard library to represent sizes and counts.

*/


/* a specialization with type string */
template<>
class Hash<string>
{
public:
  size_t operator()(const string the_key) const {
    unsigned long hash_value = 0;
    int length = (int) the_key.length();
    for (int i=0; i<length; i++)
      hash_value = 5 * hash_value + the_key.at(i);
    return size_t(hash_value);
  }
};

/* = LINEAR PROBING =
 *
 * The easiest way to find a place to put a value in the table is to search the table for
 * the next available bucket.
 *
 * On the other side, the search begins at the home bucket f(k) of the key k we are searching
 * for and continues by examining successive buckets in the table until one of the following
 * conditions happens:
 *   i) a bucket containing an entry with key k is reached
 *  ii) an empty bucket is reached
 * iii) we return to the home bucket
 */


/* hash_table class with linear probing */

template<class K, class E>
struct Entry;

template<class K, class E>
class HashTable: public Dictionary<K,E> {
public:

  bool empty() const{
    return (dsize == 0);
  };

  int size() const{
    return dsize;
  };

  void erase(const K& k);

  void modify(const K& k, const E& e);

  HashTable(int);	    // the constructor

  void create(){};

  int search(const K& ) const;

  Entry< K, E>* find(const K& ) const;

  void insert(Entry< K, E>& );

private:
 Entry<K, E>** table;    // the hash table
 Hash<K> hashm;		            // maps type K to nonnegative integer
 int dsize;		                // number of entries in dictionary
 int divisor;		            // hash function divisor
};

template<class K, class E>
HashTable<K,E>::HashTable(int the_divisor)
{
  divisor = the_divisor;
  dsize = 0;

  table = new Entry<K, E>* [divisor];
  for (int i=0; i<divisor; i++)
    table[i] = NULL;
}

/* This method returns a bucket b in the table that satisfies exactly one of the following:
 * 1) table[b] points to an entry whose key is the_key
 * 2) no entry in the table has the key the_key, table[b] is NULL
 * 3) no entry in the table has the the_key, table[b] has a key other than the_key, and the
 *   table is full
 */

template<class K, class E>
int HashTable<K,E>::search(const K& the_key) const
{
  int i = (int) hashm(the_key) % divisor;   // the home bucket
  int j = i;
  do {
    if (table[j] == NULL || table[j]->first == the_key)
      return j;
    j = (j+1) % divisor;                    // the next bucket
  } while (j != i);

  return j;                                 // the table is full
}

/* The method hash_table<K,E>::find */

template<class K, class E>
Entry< K, E>* HashTable<K,E>::find(const K& the_key) const
{
  // search the table
  int b = search(the_key);
  // see if a match was found at table[b]
  if (table[b] == NULL || table[b]->first != the_key)
    return NULL;    // no match
  return table[b];  // matching entry
}

/* = INSERTING =
 *
 * It begins by invoking the method search. If the returned bucket b is empty, then there is no
 * entry in the table with key e.first and the entry e may be inserted into this
 * bucket. If the returned bucket is not empty, then it either contains an entry with key e.first
 * or the table is full. In the former case we change the second component of the entry stored
 * in the bucket to e.second; in the latter, we throw an exception
 */

template<class K, class E>
void HashTable<K,E>::insert(Entry<K, E>& e)
{
  // search the table for a matching element
  int b = search(e.first);
  // chack if matching element found
  if (table[b] == NULL){
    // no matching element and table not full
    table[b] = new Entry<K,E> (e);
    dsize++;
  } else {
    // check id duplicate or table full
    if (table[b]->first == e.first)
      // duplicate, change table[b]->second
      table[b]->second = e.second;
    else{
      // table is full
      throw "Hash table is full";
    }
  }
}

template<class K, class E>
void HashTable<K,E>::erase(const K& k){
  //TO DO
}

template<class K, class E>
void HashTable<K,E>::modify(const K& k, const E& e){
  // TO DO
}

#endif
