#ifndef TREELIST_H
#define TREELIST_H
#define MAXNODES 100

#include "list_vector.h"
#include "Tree.h"
#include <iostream>;



template<class I>
class TreeList : public Tree<I, int> {
 public:
	typedef I item;
	typedef int node;

	// Costruttori e distruttore
	TreeList(){
		create();
	};

	void create () ;
	bool empty () const ;
	void insRoot () ;
	void insRoot (node);
	List_vector<int>::position childPos(node); //restituisce la posizione del nodo nella lista dei figli del suo genitore
	node root () const ;
	node parent (node) const ;
	bool leaf (node) const ;
	node firstChild (node) const ;
	bool lastSibling (node) const ;
	node nextSibling (node) const ;
	int size() const;
	// DA IMPLEMENTARE
	void insFirstSubTree (node, TreeList &) ;
	void insSubTree (node, TreeList &) ;
	void removeSubTree (node) ;

	void insFirst(node, item);
	void ins(node, item);

	void writeNode (node, item) ;
	item readNode (node) const ;

	void print() const;

	List_vector<int> getChilds(node n);

	int retrivepos(int a[], int b, int arrsize);

 private:
	struct Record {
		item e;
		bool used;
		List_vector<int> childs;
	};
    typedef List_vector<int>::position position_list;

	Record nodes[MAXNODES]; //100
	node _root;
	int numNodes;

};


template <class I>
void TreeList<I>::print() const{
	cout << "{";
	for (int i=0; i < MAXNODES;i++){
		if (nodes[i].used==true){
			cout << "\n  " << readNode(i) << ":  ";
			if (!leaf(i)){
				position_list child = nodes[i].childs.begin();
				while (!nodes[i].childs.end(child)){
					cout << readNode(nodes[i].childs.read(child)) << " ";
					child = nodes[i].childs.next(child);
				}
			}
		}

	}
	cout << "\n}\n";
}

template <class I>
void TreeList<I>::create(){
	numNodes = 0;
	for (int i=0; i< MAXNODES;i++){
		nodes[i].used = false;
		nodes[i].childs.create();
	}
}

template <class I>
bool TreeList<I>::empty() const{
	return(numNodes == 0);
}

template <class I>
void TreeList<I>::insRoot (){
	if (empty()){
		_root = 0;
		nodes[0].used = true;
		numNodes++;
	}
}

template <class I>
void TreeList<I>::insRoot (node n){
	if (empty()){
		_root = n;
		nodes[_root].used = true;
		numNodes++;
	}
}

template <class I>
typename TreeList<I>::node TreeList<I>::root () const{
	return _root;
}

template <class I>
typename TreeList<I>::node TreeList<I>::parent (node n) const{
	position_list child;
	//int p; NON Utilizzato
	for (int i=0; i < MAXNODES; i++){
		if (!nodes[i].childs.empty()){
			child = nodes[i].childs.begin();
			bool found = false;
			while (!nodes[i].childs.end(child) && !found){
				if (nodes[i].childs.read(child) == n){
					found = true;
					//p = i; NON Utilizzato
				}
				child = nodes[i].childs.next(child);
			}
			if (found)
				return(i);
		}
	}
}

template <class I>
bool TreeList<I>::leaf(node n) const{ //è una foglia se non ha figli
	return(nodes[n].childs.empty());
}

template <class I>
typename TreeList<I>::node TreeList<I>::firstChild (node n) const{
	if (!leaf(n)){
		return(nodes[n].childs.read(nodes[n].childs.begin()));
	}
}

template <class I>
bool TreeList<I>::lastSibling (node n) const {
	position_list c;
	node p = parent(n);
	c = nodes[p].childs.begin();
	return (n == nodes[p].childs.read(nodes[p].childs.size()));
	/*while (!nodes[p].childs.end(c))
		c = nodes[p].childs.next(c);
	return (n == nodes[p].childs.read(c));*/
}

template <class I>
typename TreeList<I>::node TreeList<I>::nextSibling (node n) const{
	if (!lastSibling(n)){
		position_list c;
		node p = parent(n);
		c = nodes[p].childs.begin();
		while (!nodes[p].childs.end(c)){
			if (nodes[p].childs.read(c) == n)
				return (nodes[p].childs.read(nodes[p].childs.next(c)));
			c = nodes[p].childs.next(c);
		}
	}
}

template <class I> // inserisce un node come firstChild di n
void TreeList<I>::insFirst(node n, item el){
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		nodes[n].childs.insert(k, nodes[n].childs.begin());
	}
	numNodes++;
}

template <class I> // inserisce un node come fratello di n(nodo già esistente)
void TreeList<I>::ins(node n, item el){
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
        numNodes++;
		nodes[k].used = true;
		nodes[k].e = el;
		node p = parent(n); //estrae il genitore di n
		if (p!=0 || p<MAXNODES)
            nodes[p].childs.insert(k ,nodes[p].childs.size()+1); //Inserisce il nodo nella lista dei figli di p (genitore di n) nell'ultima posizione

		/*position_list child = nodes[p].childs.begin();
		bool found = false;
		while (!nodes[p].childs.end(child) && !found){
			if (nodes[p].childs.read(child) == n)
					found = true;
			child = nodes[p].childs.next(child);
		}
		nodes[p].childs.insert(k,nodes[p].childs.begin());// child);*/
	}
}


template <class I> //Rimuove il sottoalbero del nodo n
void TreeList<I>::removeSubTree (node n){
	position_list c;
	if (!leaf(n)){
		while (!nodes[n].childs.empty()){
			removeSubTree(nodes[n].childs.read(nodes[n].childs.begin()));
		}
	}
	node p = parent(n);
	c = nodes[p].childs.begin();
	while(nodes[p].childs.read(c) != n)
		c = nodes[p].childs.next(c);
	nodes[p].childs.erase(c);
	nodes[n].used = false;
}

template <class I>
void TreeList<I>::writeNode (node n, item el){
	nodes[n].e = el;
}

template <class I>
typename TreeList<I>::item TreeList<I>::readNode (node n) const{
	return(nodes[n].e);
}

template <class I>
int TreeList<I>::size() const{
    return numNodes;
}

template <class I>
List_vector<int>::position TreeList<I>::childPos(node son){
    if (son != root()){
        position_list p = nodes[parent(son)].childs.begin();
        while (nodes[parent(son)].childs.read(p)!= son){
            p = nodes[parent(son)].childs.next(p);
        }
        return p;
    }
}

template <class I>
List_vector<int> TreeList<I>::getChilds(node n){
    return (nodes[n].childs);
}

template <class I>
void TreeList<I>::insFirstSubTree(node n, TreeList & T){
    int k;
    int o = 0, t = 0;
	int oldn[T.size()];
	int newn[T.size()];

    for (int i = 0; i < T.size(); i++)
        for (k = 0; k < MAXNODES; k++){
            if (nodes[k].used == false){
                nodes[k].used = true;
                nodes[k].e = T.readNode(i);
                nodes[k].childs = T.getChilds(i);
                oldn[o] = i;
                newn[o] = k;
                o++;
                if (i==0)
                   t = k;
                numNodes++;
                break;
            }
        }

   for (int i = 0; i < T.size(); i++){
    if (!leaf(newn[i])){
            List_vector<int>::position poschildlist = nodes[newn[i]].childs.begin();
            node secTreeChildPos = T.firstChild(i);
            for (int j = 1; j<=T.getChilds(i).size() && !nodes[newn[i]].childs.end(poschildlist); j++){
                nodes[newn[i]].childs.write(newn[retrivepos(oldn, T.getChilds(i).read(j), T.size())], poschildlist);
                poschildlist = nodes[newn[i]].childs.next(poschildlist);
                secTreeChildPos = T.nextSibling(secTreeChildPos);
            }
        }
   }
   nodes[n].childs.insert(t, nodes[n].childs.begin());
}


template <class I>
void TreeList<I>::insSubTree(node n, TreeList & T){
    int k;
    int o = 0, t = 0;
	int oldn[T.size()];
	int newn[T.size()];

    for (int i = 0; i < T.size(); i++)
        for (k = 0; k < MAXNODES; k++){
            if (nodes[k].used == false){
                nodes[k].used = true;
                nodes[k].e = T.readNode(i);
                nodes[k].childs = T.getChilds(i);
                oldn[o] = i;
                newn[o] = k;
                o++;
                if (i==0)
                   t = k;
                numNodes++;
                break;
            }
        }

   for (int i = 0; i < T.size(); i++){
    if (!leaf(newn[i])){
            List_vector<int>::position poschildlist = nodes[newn[i]].childs.begin();
            node secTreeChildPos = T.firstChild(i);
            for (int j = 1; j<=T.getChilds(i).size() && !nodes[newn[i]].childs.end(poschildlist); j++){
                nodes[newn[i]].childs.write(newn[retrivepos(oldn, T.getChilds(i).read(j), T.size())], poschildlist);
                poschildlist = nodes[newn[i]].childs.next(poschildlist);
                secTreeChildPos = T.nextSibling(secTreeChildPos);
            }
        }
   }
   nodes[n].childs.insert(t, nodes[n].childs.size()+1);
}


template <class I>
int TreeList<I>::retrivepos(int a[], int b, int arrsize){
    for (int i = 0; i<arrsize; i++){
        if (b == a[i])
            return (i);
    }
}

#endif
