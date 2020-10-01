#ifndef CODEPT_H_INCLUDED
#define CODEPT_H_INCLUDED

#include <iostream>
#include "nodocpt.h"

using namespace std;

template <class T>
class CodaPT{

  friend void stampaCoda(CodaPT & L);

  public:
    CodaPT();
    ~CodaPT();
    void create();
    bool empty() const;
    T top() const;
    void pop();
    void push(T);
    int size() const;
  private:
    NodoCPT<T>* head;
    NodoCPT<T>* tail;
    int length;
  };


template <class T>
CodaPT<T>::CodaPT(){
    create();
}

template <class T>
CodaPT<T>::~CodaPT(){
    while(!empty()){
        pop();
    }
    delete head;
    delete tail;
}

template <class T>
void CodaPT<T>::create(){
    //head=tail;
    //tail=head;
    length=0;
}

template <class T>
bool CodaPT<T>::empty() const
  {
    return (length==0);
  }

template <class T>
int CodaPT<T>::size() const
  {
    return(length);
  }


template <class T>
T CodaPT<T>::top() const
  {
    T x= NULL;
    if(length>=1)
        return head->getElemento();
    else{

        cout<<"coda vuotaa"<<endl;}

       return x;
    }



template <class T>
void CodaPT<T>::pop() //DA VEDERE DELETE??
  {
      if(length>0){
        //NodoCPT<T> *temp = new NodoCPT<T>();
        //temp=head;
        head=head->getNext();
        length--;
        //delete temp;
      }
      //if(empty())
        //cout<<""<<endl;
  }


template <class T>
void CodaPT<T>::push(T el)
  {
    NodoCPT<T>* nuovo= new NodoCPT<T>;
    nuovo->setElemento(el);
    nuovo->setPrev(tail);
    tail->setNext(nuovo);
    tail= nuovo;
    if(length == 0){
        head=tail;
    }
    length++;
  }



#endif // CODEPT_H_INCLUDED
