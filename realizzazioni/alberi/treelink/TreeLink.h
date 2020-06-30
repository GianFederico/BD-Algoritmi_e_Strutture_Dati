/***************************************************************************
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
#ifndef TREELINK_H
#define TREELINK_H

#include <iostream>

template<class I>
class TreeLink;

template<class I>
class TreeNode {
	friend class TreeLink<I>;
	private:
		TreeNode<I> * _parent = nullptr;
		TreeNode<I> * _firstChild = nullptr;
	  TreeNode<I> * _nextSibling = nullptr;
	  I _item;
};


template<class I>
class TreeLink {
 public:

	typedef I item;
	typedef TreeNode<I>* node;

	// Costruttori e distruttore
	TreeLink(){
		create();
	};

	void create () ;
	bool empty () const ;
	void insRoot (item) ;
	node root () const ;
	node parent (node) const ;
	bool leaf (node) const ;
	node firstChild (node) const ;
	bool lastSibling (node) const ;
	node nextSibling (node) const ;
	// DA IMPLEMENTARE
	//	void insFirstSubTree (node, TreeList &) ;
	//	void insSubTree (node, TreeList &) ;
	void removeSubTree (node) ;

	void insFirst(node, item);
	void ins(node, item);

	void writeNode (node, item) ;
	item readNode (node) const ;

	void print(node n) const;

 private:
	node _root;

};

template <class I>
void TreeLink<I>::create(){
	_root = nullptr;
}

template <class I>
bool TreeLink<I>::empty() const{
	return(_root==nullptr);
}

template <class I>
void TreeLink<I>::insRoot (item i){
	_root=new TreeNode<I>();
	_root->_item=i;
}

template <class I>
void TreeLink<I>::print(node n) const {
	using namespace std;
	node p;
	cout << n->_item << ":";
	if (!leaf(n)) {
		p=firstChild(n);
		while (!lastSibling(p)) {
			cout << " " << p->_item;
			p=nextSibling(p);
		}
		cout << " " << p->_item << endl;
		p=firstChild(n);
		while (!lastSibling(p)) {
			print(p);
			p=nextSibling(p);
		}
		print(p);
	} else {
		cout << endl;
	}
}

template <class I>
typename TreeLink<I>::node TreeLink<I>::root () const{
	return _root;
}

template <class I>
typename TreeLink<I>::node TreeLink<I>::parent (node n) const{
	if (n->_parent!=nullptr)
		return n->_parent;
}

template <class I>
bool TreeLink<I>::leaf(node n) const{
	return (n->_firstChild==nullptr);
}

template <class I>
typename TreeLink<I>::node TreeLink<I>::firstChild (node n) const{
	if (!leaf(n)){
		return n->_firstChild;
	}
}

template <class I>
bool TreeLink<I>::lastSibling (node n) const {
	return (n->_nextSibling==nullptr);
}

template <class I>
typename TreeLink<I>::node TreeLink<I>::nextSibling (node n) const{
	if (!lastSibling(n)){
		return n->_nextSibling;
	}
}


// inserisce un node come firstChild di n
template <class I>
void TreeLink<I>::insFirst(node n, item el){
	node newnode=new TreeNode<I>();
	newnode->_item=el;
	newnode->_nextSibling=n->_firstChild;
	newnode->_parent=n;
	n->_firstChild=newnode;
}

// inserisce un node come fratello di n
template <class I>
void TreeLink<I>::ins(node n, item el){
	node newnode=new TreeNode<I>();
	newnode->_item=el;
	newnode->_nextSibling=n->_nextSibling;
	newnode->_parent=n->_parent;
	n->_nextSibling=newnode;
}

template <class I>
void TreeLink<I>::removeSubTree (node n){
	node p;
	if (!leaf(n)){
		p=n->_firstChild;
    	while (!lastSibling(p)) {
    		removeSubTree(p);
    		p=p->_nextSibling;
		}
		removeSubTree(p);
	}
	p = parent(n)->_firstChild;
	if (p==n) {
		parent(n)->_firstChild=p->_nextSibling;
		delete n;
	} else {
		while (!lastSibling(p) || p->_nextSibling!=n) {
			p=p->_nextSibling;
		}
		p->_nextSibling=p->_nextSibling->_nextSibling;
		delete p->_nextSibling;
	}
}

template <class I>
void TreeLink<I>::writeNode (node n, item el){
	n->_item=el;
}

template <class I>
typename TreeLink<I>::item TreeLink<I>::readNode (node n) const{
	return n->_item;
}



#endif
