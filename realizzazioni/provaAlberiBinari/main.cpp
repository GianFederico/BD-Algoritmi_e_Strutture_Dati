#include <iostream>
#include "../../realizzazioni/alberibin/Bin_tree.h"
#include "../../realizzazioni/alberibin/Bin_treec.h"
#include "../../realizzazioni/alberibin/exceptions.h"

using namespace std;


int PROVA_ALBERIBIN(){
	Bin_treec<int> T;
	typename Bin_treec<int>::Nodo n1, n2;

	T.ins_root(n1);
	T.write(T.root(),1);
	n1 = T.root();
	T.ins_sx(n1);
	T.ins_dx(n1);


	T.write(T.sx(n1),2);
	n1=T.sx(n1);
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1),4);
	T.write(T.dx(n1),5);

	n1 = T.dx(T.parent(n1));
	T.write(n1, 3);
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1),6);
	T.write(T.dx(n1),7);

	T.print();


	cout << T;

	T.previsit(T.root());
	cout<<endl;
	T.invisit(T.root());
	cout<<endl;
	T.postvisit(T.root());
}

int main(){
    PROVA_ALBERIBIN();

}
