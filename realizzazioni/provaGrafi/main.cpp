#include <iostream>
//#include "../../realizzazioni/grafi/GrafoList.h"
#include "../../realizzazioni/grafi/GrafoMat.h"

#include <string>

using namespace std;

/*void PROVA_GRAFI_LIST(){
    GrafoList<char,double> G(10);

    NodoG n1,n2,n3,n4,n5,n6;

    G.insNodo(n1);
    G.scriviEtichetta(n1,'a');
    G.insNodo(n2);
    G.scriviEtichetta(n2,'b');
    G.insNodo(n3);
    G.scriviEtichetta(n3,'c');
    G.insNodo(n4);
    G.scriviEtichetta(n4,'d');
    G.insNodo(n5);
    G.scriviEtichetta(n5,'e');
    G.insNodo(n6);
    G.scriviEtichetta(n6,'f');



    G.insArco(n1,n2, 1.0);
    G.insArco(n1,n3, 0.9);
    G.insArco(n1,n5, 0.3);
    G.insArco(n2,n4, 0.1);
    G.insArco(n2,n6, 0.2);
    G.insArco(n3,n4, 1.0);
    G.insArco(n3,n6, 0.7);
    G.insArco(n4,n1, 0.5);
    G.insArco(n5,n2, 0.4);
    G.insArco(n5,n3, 0.2);
    G.insArco(n6,n4, 0.1);

    cout << "\nNumNodi " << G.numNodi();
    cout << "\nNumArchi " << G.numArchi();

    GrafoList<string,double>::ListaNodi L = G.Adiacenti(n2);

    GrafoList<string,double>::ListaNodiPos p;


    cout << "\nAdiacenti di " << G.leggiEtichetta(n2) << "--> ";
    p = L.begin();
    while (!L.end(p)){
        cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
        p = L.next(p);
    }
    cout << endl;

    G.cancNodo(n2);
    cout << "\nNumNodi " << G.numNodi();
    cout << "\nNumArchi " << G.numArchi();

    L = G.Adiacenti(n1);

    cout << "\nAdiacenti di " << G.leggiEtichetta(n1) << "--> ";
    p = L.begin();
    while (!L.end(p)){
        cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
        p = L.next(p);
    }

    cout<<endl;
    G.printEtichette();

    cout<<endl;
    if(!G.esisteNodo(n1))
        cout<<"not";
    else
        cout<<"yes";
}*/


int PROVA_GRAFI_MAT(){
	GrafoMat<string,double> G(10);

	NodoG n1,n2,n3,n4,n5,n6;

	G.insNodo(n1);
	G.scriviEtichetta(n1,"a");
	G.insNodo(n2);
	G.scriviEtichetta(n2,"b");
	G.insNodo(n3);
	G.scriviEtichetta(n3,"c");
	G.insNodo(n4);
	G.scriviEtichetta(n4,"d");
	G.insNodo(n5);
	G.scriviEtichetta(n5,"e");
	G.insNodo(n6);
	G.scriviEtichetta(n6,"f");


	G.insArco(n1,n2, 1.0);
	G.insArco(n1,n3, 0.9);
	G.insArco(n1,n5, 0.3);
	G.insArco(n2,n4, 0.1);
	G.insArco(n2,n6, 0.2);
	G.insArco(n3,n4, 1.0);
	G.insArco(n3,n6, 0.7);
	G.insArco(n4,n1, 0.5);
	G.insArco(n5,n2, 0.4);
	G.insArco(n5,n3, 0.2);
	G.insArco(n6,n4, 0.1);

	cout << "\nNumNodi " << G.numNodi();
	cout << "\nNumArchi " << G.numArchi();

	G.cancNodo(n6);

	cout << "\nNumNodi " << G.numNodi();

	GrafoMat<string,double>::ListaNodi L = G.Adiacenti(n1);

	GrafoMat<string,double>::ListaNodiPos p;


	cout << "\nAdiacenti di " << G.leggiEtichetta(n1) << "--> ";
	p = L.begin();
	while (!L.end(p)){
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
		p = L.next(p);
	}

	cout << endl;

	L = G.Adiacenti(n3);
	cout << "\nAdiacenti di " << G.leggiEtichetta(n3) << "--> ";
	p = L.begin();
	while (!L.end(p)){
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
		p = L.next(p);
	}

	G.cancNodo(n3);
    L = G.Adiacenti(n1);
	cout << "\nAdiacenti di " << G.leggiEtichetta(n1) << "--> ";
	p = L.begin();
	while (!L.end(p)){
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
		p = L.next(p);
	}

    	cout << endl;
    if(!G.esisteNodo(n1))
        cout<<"not";
    else
        cout<<"yes";

    GrafoMat<string,double>::Arco arco;
    arco.nodo1=n1;
    arco.nodo2=n3;
    arco.peso=0;

       	cout << endl;
    if(!G.esisteArco(arco))
        cout<<"not";
    else
        cout<<"yes";


}

int main()
{
    //PROVA_GRAFI_LIST();
    PROVA_GRAFI_MAT();
    return 0;
}
