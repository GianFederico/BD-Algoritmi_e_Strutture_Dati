#ifndef GRAFOLIST_H
#define GRAFOLIST_H

#include "Grafo.h"
#include "list_vector.h"

class NodoG{
  public:
    NodoG(int i){
      nodoId = i;
    }
    NodoG(){
    }
    int getId(){ return nodoId; }
    void setId(int id) {nodoId = id;}
  private:
    int nodoId; //Posizione nella matrice
};


template<class P>
class InfoArco {
  public:
    P peso;
    NodoG _to;
};


template<class E, class P>
class InfoNodo {
  public:
    E   etichetta;
    bool vuoto;
    List_vector<InfoArco<P>> archi;

    InfoNodo(){
      vuoto = true;
    }

    ~InfoNodo(){
	  }
};



template<class E, class P>
  class GrafoList : public Grafo<E, P, NodoG> {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoList(int);
    ~GrafoList();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
    bool esisteNodo(Nodo);
    bool esisteArco(Arco);
    ListaNodi Adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;
    void printEtichette();
    bool esisteArco(Nodo, Nodo) const;
    typename List_vector<InfoArco<P> >::position searchArcoPos(Nodo, Nodo) const;

    int numNodi(){
      return nodi;
    };
    int numArchi(){
      return archi;
    };


 private:
    InfoNodo<E,P>* matrice;
    int dimensione; //Numero massimo di nodi (dimensione matrice)
    int nodi;       //Numero di nodi utilizzati
    int archi;      //Numero di archi
};


template<class E, class P>
GrafoList<E, P>::GrafoList(int _dimensione){
  dimensione = _dimensione;
  nodi = 0;
  archi = 0;
  matrice = new InfoNodo<E,P>[dimensione];
  for (int i=0; i<dimensione; i++)
    matrice[i].archi.create();
}

template<class E, class P>
GrafoList<E, P>::~GrafoList() {
  delete [] matrice;
}

template<class E, class P>
bool GrafoList<E, P>::vuoto() const {
  return (nodi == 0);
}

template<class E, class P>
void GrafoList<E, P>::insNodo(Nodo& N) {
  int n = 0;
  if (nodi < dimensione){
    while (matrice[n].vuoto == false)
      n++;
    nodi++;
    matrice[n].vuoto = false;
  }
  N.setId(n);
}

template<class E, class P>
void GrafoList<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
  InfoArco<P> I;
  I.peso = peso;
  I._to = n2;
  matrice[n1.getId()].archi.insert(I, matrice[n1.getId()].archi.begin());
  archi++;
}

template<class E, class P>
void GrafoList<E, P>::cancNodo(Nodo n) {
  bool canc = false;
  int i = 0;
  typename List_vector<InfoArco<P>>::position p;
  p= matrice[n.getId()].archi.begin();

  if (matrice[n.getId()].archi.empty())
    canc = true;
  else {
    while (!matrice[n.getId()].archi.end(p) && !matrice[n.getId()].archi.empty()){ //Svuota la lista degli archi uscenti da n
        matrice[n.getId()].archi.erase(p);
        archi--;
    }
    canc = true;
  }
    for (i = 0; i<dimensione; i++)                      //Ricerca ed elimina tutti gli archi entranti in n
         cancArco(i, n);
  if (canc){    // la lista  matrice[n.getId()].archi è vuota e gli altri nodi non hanno archi entranti in n;
    matrice[n.getId()].vuoto = true;
    nodi--;
    }
}

template<class E, class P>
void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2){
	if (esisteArco(n1, n2)){
        typename List_vector<InfoArco<P> >::position p = searchArcoPos(n1, n2);
		matrice[n1.getId()].archi.erase(p);
        archi--;
    }
}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::Adiacenti(Nodo n) const{
  ListaNodi list;
  typename List_vector<InfoArco<P>>::position p;
	p = matrice[n.getId()].archi.begin();
  while (!matrice[n.getId()].archi.end(p)){
		list.insert(new NodoG(matrice[n.getId()].archi.read(p)._to), list.begin());
	  p = matrice[n.getId()].archi.next(p);
	}
  return list;

}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::list_nodi() const {
  ListaNodi list;
  for (int i = 0; i < dimensione; i++)
    if (!matrice[i].vuoto)
      list.insert(new NodoG(i), list.begin());
  return list;
}

template<class E, class P>
E GrafoList<E, P>::leggiEtichetta(Nodo n) const {
  if (!matrice[n.getId()].vuoto)
  return matrice[n.getId()].etichetta;
  else cout<<"Nodo non esistente\n";
}

template<class E, class P>
void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta) {
  if (!matrice[n.getId()].vuoto)
  matrice[n.getId()].etichetta = etichetta;
  else cout<<"Nodo non esistente\n";
}

template<class E, class P>
P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	if (esisteArco(n1, n2)){
        typename List_vector<InfoArco<P> >::position p = searchArcoPos(n1, n2);
		return matrice[n1.getId()].archi.read(p).peso;
	}
    else
        cout<<"I due nodi "<<leggiEtichetta(n1)<<" e "<<leggiEtichetta(n2)<<" non sono adiacenti";

}

template<class E, class P>
void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	if (esisteArco(n1, n2)){
        typename List_vector<InfoArco<P> >::position p = searchArcoPos(n1, n2);
		InfoArco<P> I;
		I.peso = peso;
		I._to = n2;
		matrice[n1.getId()].archi.write(I,p);
	}
}

template <class E, class P>
void GrafoList<E, P>::printEtichette(){
    E a[numNodi()];
	int i = 0;
    ListaNodiPos p = list_nodi().begin();
    while (!list_nodi().end(p)){
        a[++i]=leggiEtichetta(*(list_nodi().read(p)));
        p = list_nodi().next(p);
    }
    while (i>0)
        cout<<a[i--]<<" ";
}

template <class E, class P>
bool GrafoList<E, P>::esisteNodo(Nodo n){
    if (!matrice[n.getId()].vuoto)
        return true;
    else
        return false;
}

template <class E, class P>
bool GrafoList<E, P>::esisteArco(Arco a){
    return esisteArco(a.nodo1, a.nodo2);
}

template <class E, class P>
bool GrafoList<E, P>::esisteArco(Nodo n1, Nodo n2) const{
    typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	return trovato;
}

template <class E, class P>
typename List_vector<InfoArco<P> >::position GrafoList<E, P>::searchArcoPos(Nodo n1, Nodo n2) const{
    typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	return p;
}


#endif
