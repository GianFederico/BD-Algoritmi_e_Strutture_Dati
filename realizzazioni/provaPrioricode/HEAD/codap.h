#ifndef _CODAP_H_
#define _CODAP_H_
#include <iostream>
using namespace std;

template < class T >
class CodaP {

  public:
    CodaP ();
    CodaP (int);
    ~CodaP ();

    void creaPrioriCoda ();
    void inserisci (T);
    T min ();
    void cancellaMin ();
    void print();

  private:
    int MAXLUNG; //massima lunghezza della coda
    T *heap;
    int ultimo; //(ultimo-1 = ultimo elem nella coda) quanti elementi ci sono nella coda

    void fixUp ();
    void fixDown (int, int);
};


template < class T > CodaP < T >::CodaP ():MAXLUNG (100) {
  heap = new T[MAXLUNG];
  creaPrioriCoda ();
};

template < class T > CodaP < T >::CodaP (int maxN): MAXLUNG (maxN) {
  heap = new T[MAXLUNG];
  creaPrioriCoda ();
};

template < class T > CodaP < T >::~CodaP () {
  delete[] heap;
};

template < class T > void CodaP < T >::creaPrioriCoda () {
  ultimo = 0;
};

template < class T > void CodaP < T >::inserisci (T e) {
  if (ultimo < MAXLUNG){ //end program if ultimo>=MAXLUNG
    heap[++ultimo - 1] = e; //incrementa prima ultimo (ultimo punta alla prima posizione libera nel vettore) e copia il nuovo valore prima di ultimo
    fixUp (); //fai risalire verso l'alto
  }
};

template < class T > T CodaP < T >::min () {
  if(ultimo != 0) //nel caso di coda vuota ultimo==0
    return (heap[0]);
};

template < class T > void CodaP < T >::cancellaMin () {
  if(ultimo != 0){ //nel caso di coda vuota ultimo==0

    heap[0] = heap[ultimo - 1]; //copia il valore dell'ultima foglia nella radice

    ultimo--;
    fixDown (1,ultimo); //fai scendere verso il basso
  }
};


/* Per ripristinare i vincoli dello heap quando la priorità di un nodo è      *
 * cresciuta, ci spostiamo nello heap verso l'alto, scambiando, se necessario,*
 * il nodo in posizione k con il suo nodo padre (in posizione k/2),           *
 * continuando fintanto che heap[k]<heap[k/2] oppure fino a quando            *
 * raggiungiamo la cima dello heap.                                           */

template < class T > void CodaP < T >::fixUp () {
  int k = ultimo;

  while (k > 1 && heap[k - 1] < heap[k / 2 - 1]) {
      T tmp;
      tmp = heap[k - 1];
      heap[k - 1] = heap[k / 2 - 1];
      heap[k / 2 - 1] = tmp;
      k = k / 2;
    }

}

/* Per ripristinare i vincoli dello heap quando la priorità di un nodo si è   *
 * ridotta, ci spostiamo nello heap verso il basso, scambiando, se necessario,*
 * il nodo in posizione k con il minore dei suoi nodi figli e arrestandoci    *
 * quando il nodo al posto k non è più grande di almeno uno dei suoi figli    *
 * oppure quando raggiungiamo il fondo dello heap. Si noti che se N è pari e  *
 * k è N/2, allora il nodo in posizione k ha un solo figlio: questo caso      *
 * particolare deve essere trattato in modo appropriato.                      */

template < class T > void CodaP < T >::fixDown (int k, int N) {

  short int scambio = 1;

  while (k <= N / 2 && scambio) {
      int j = 2 * k;
      T tmp;
      if (j < N && heap[j - 1] > heap[j])
				j++;
      if ((scambio = (heap[j - 1] < heap[k - 1]))) {
				tmp = heap[k - 1];
				heap[k - 1] = heap[j - 1];
				heap[j - 1] = tmp;
				k = j;
			}
  }
};

template < class T >
void CodaP< T >::print() {
    int i=0;
    while(i<ultimo){
       cout<<heap[i]<<" ";
        i++;
    }
};



#endif /* _CODAP_H_ */
