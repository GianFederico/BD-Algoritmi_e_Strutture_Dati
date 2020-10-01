#ifndef NODOCPT_H_INCLUDED
#define NODOCPT_H_INCLUDED
#include <iostream>

using namespace std;


template <class T>
class NodoCPT{
typedef T tipoelem;
  public:

    NodoCPT();
    NodoCPT(tipoelem);
    ~NodoCPT();

    void setElemento(tipoelem);
    tipoelem getElemento() const;
    void setNext(NodoCPT<T>*);
    NodoCPT<T>* getNext();
    void setPrev(NodoCPT<T>*);
    NodoCPT<T>* getPrev();
    bool operator ==(NodoCPT<T> &);

  private:
    tipoelem elemento; //etichetta
    NodoCPT<T>* next;
    NodoCPT<T>* prev;

  };


template <class T>
NodoCPT<T>::NodoCPT()
{
    next=nullptr;
}

template <class T>
NodoCPT<T>::~NodoCPT()
{
    delete(next);
}

template <class T>
NodoCPT<T>::NodoCPT(tipoelem label)
{
  elemento=label;
}

template <class T>
void NodoCPT<T>::setElemento(tipoelem label)
{
  elemento=label;
}

template <class T>
T NodoCPT<T>::getElemento() const
{
    return elemento;
}

template <class T>
void NodoCPT<T>::setNext(NodoCPT<T>* ptr)
{
next=ptr;
}

template <class T>
NodoCPT<T>* NodoCPT<T>::getNext(){
    return next;
}

template <class T>
void NodoCPT<T>::setPrev(NodoCPT<T>* ptr)
{
prev=ptr;
}

template <class T>
NodoCPT<T>* NodoCPT<T>::getPrev(){
    return prev;
}


template <class T>
bool NodoCPT<T>::operator==(NodoCPT & n)
{
  return (getElemento() == n.getElemento());
}

template <class T>
ostream & operator<<(ostream & out, const NodoCPT<T> & nodo)
{
  return out << nodo.getElemento();
}







#endif // NODOCPT_H_INCLUDED
