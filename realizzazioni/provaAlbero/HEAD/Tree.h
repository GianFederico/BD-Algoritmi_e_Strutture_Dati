#ifndef TREE_H
#define TREE_H

template<class I, class N>
	class Tree {
 public:
	typedef I item;
	typedef N node;

	virtual void create () = 0;
	virtual bool empty () const = 0;
	virtual void insRoot () = 0;    //prima c'era node come argomento, da cambiare anche in treelist nel caso
	virtual node root () const = 0;
	virtual node parent (node) const = 0;
	virtual bool leaf (node) const = 0;
	virtual node firstChild (node) const = 0;
	virtual bool lastSibling (node) const = 0;
	virtual node nextSibling (node) const = 0;
	// DA IMPLEMENTARE
	//	virtual void insFirstSubTree (node, Tree &) = 0;
	//	virtual void insSubTree (node, Tree &) = 0;
	virtual void removeSubTree (node) = 0;

	virtual void writeNode (node, item) = 0;
	virtual item readNode (node) const = 0;

	//template<class V> void BFS(node);
	//template<class V> void preorder(node);
	//template<class V> void postorder(node);

};

#endif
