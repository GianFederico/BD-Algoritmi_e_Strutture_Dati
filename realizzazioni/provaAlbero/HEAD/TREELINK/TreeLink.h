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
	void insFirstSubTree (node, TreeLink &) ;
	void insSubTree (node, TreeLink &) ;
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



template <class I>  // inserisce un node come firstChild di n
void TreeLink<I>::insFirst(node n, item el){
	node newnode=new TreeNode<I>();
	newnode->_item=el;
	newnode->_nextSibling= n->_firstChild;
	newnode->_parent=n;
	n->_firstChild=newnode;
}


template <class I>  // inserisce un node come fratello di n
void TreeLink<I>::ins(node n, item el){
	node newnode=new TreeNode<I>();
	newnode->_item=el;
	newnode->_nextSibling= n->_nextSibling;
	newnode->_parent= n->_parent;
	n->_nextSibling=newnode;
}

template <class I>
void TreeLink<I>::removeSubTree (node n){
	node p;
	if (!leaf(n)){
		p= n->_firstChild;
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


template <class I>
void TreeLink<I>::insFirstSubTree (node n, TreeLink & T) {
    node newnode=T.root();
	newnode->_nextSibling= n->_firstChild;
	newnode->_parent=n;
	n->_firstChild=newnode;
}

template <class I>
void TreeLink<I>::insSubTree (node n, TreeLink & T) {
    node newnode=T.root();
	newnode->_nextSibling= n->_nextSibling;
	newnode->_parent= n->_parent;
	n->_nextSibling=newnode;
}




#endif
