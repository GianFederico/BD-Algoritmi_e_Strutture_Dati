#ifndef PILAPT_H
#define PILAPT_H
#include <iostream>
#include "nodoppt.h"

using namespace std;

template <class T>
class PilaPT{
  friend void stampaPila(PilaPT & L);

  public:
    PilaPT();
    ~PilaPT();
    void create();
    bool empty() const;
    tipoelem top() const;
    void pop();
    void push(tipoelem);
    int size() const;
  private:
    NodoPT<T>* head;
    int length;
  };


template <class T>
PilaPT<T>::PilaPT(){
    create();
}

template <class T>
PilaPT<T>::~PilaPT(){
    while(!empty()){
        pop();
    }
    delete head;
}

template <class T>
void PilaPT<T>::create(){
    head=nullptr;
    length=0;
}

template <class T>
bool PilaPT<T>::empty() const
  {
    return (head==nullptr);
  }

template <class T>
int PilaPT<T>::size() const
  {
    return(length);
  }


template <class T>
tipoelem PilaPT<T>::top() const
  {
    tipoelem x= NULL;
    if(!empty())
        return head->getElemento();
    else{

        cout<<"pila vuotaa"<<endl;}

       return x;
    }



template <class T>
void PilaPT<T>::pop() //DA VEDERE DELETE??
  {
      if(!empty()){
        //NodoPT<T> *temp = new NodoPT<T>();
        //temp=head;
        head=head->getPrev();
        length--;
        //delete temp;
      }
      if(empty())
        cout<<"pila vuota"<<endl;
  }


template <class T>
void PilaPT<T>::push(tipoelem el)
  {
    NodoPT<T>* nuovo= new NodoPT<T>;
    nuovo->setElemento(el);
    nuovo->setPrev(head);
    head= nuovo;
    length++;
  }










/*template <class T>
class mystackpt
  {
  public:
    typedef T tipoelem;

    mystackpt();
    mystackpt(const mystackpt<T>&);
    ~mystackpt();

    void create();
    bool empty() const;
    tipoelem top() const;
    void pop();
    void push(tipoelem);

    mystackpt<T>& operator=(const mystackpt<T>&);

    template <class K>
    friend ostream& operator<<(ostream& os, const mystackpt<K>&);

  private:
    cell<T>* head;
  };

template <class T>
mystackpt<T>::mystackpt()
{
  head = nullptr;
}

template <class T>
mystackpt<T>::mystackpt(const mystackpt<T>& p){

  if(!p.empty()){
    head=new cell<T>();
    head->value=p.head->value;

    cell<T>* tocpy=p.head->prev;
    cell<T>* whcpy=head;

    while(tocpy!=nullptr){

      cell<T>*tmp=new cell<T>();
      tmp->value=tocpy->value;

      whcpy->prev=tmp;

      tocpy=tocpy->prev;
      whcpy=whcpy->prev;
    }
  }else throw "can't copy empty stack";
}


template <class T>
mystackpt<T>::~mystackpt()
{
  while (!empty())
    pop();
};

template <class T>
void mystackpt<T>::create()
{
  head=nullptr;
}

template <class T>
bool mystackpt<T>::empty() const
  {
    return head==nullptr;
  }

template <class T>
T mystackpt<T>::top() const
  {
    return head->value;
  }

template <class T>
void mystackpt<T>::pop()
{
  if (!empty())
    {
      cell<T> *tmp = head;
      head = head->prev;
      delete tmp;
    }
}

template <class T>
void mystackpt<T>::push(tipoelem el)
{
  cell<T> *tmp = new cell<T>();
  tmp->value = el;
  tmp->prev = head;
  head = tmp;
}

template <class T>
mystackpt<T>& mystackpt<T>::operator=(const mystackpt<T>&p){

    if(this==&p) return *this;

    if(!p.empty()){

      while (!empty())
        pop();

      head=new cell<T>();
      head->value=p.head->value;

      cell<T>* tocpy=p.head->prev;
      cell<T>* whcpy=head;

      while(tocpy!=nullptr){

        cell<T>*tmp=new cell<T>();
        tmp->value=tocpy->value;

        whcpy->prev=tmp;

        tocpy=tocpy->prev;
        whcpy=whcpy->prev;

      }

    }else throw "can't copy empty stack";

    return *this;
}

template <class K>
ostream& operator<<(ostream& os, const mystackpt<K>&p){

  os<<"TOP[";

  if(!p.empty()){
    cell<K>* tmp=p.head;

    while(tmp->prev!=nullptr) {
      os<<tmp->value<<"|";
      tmp=tmp->prev;
    }
    os<<tmp->value;
  }

  os<<"]BOT"<<endl;

  return os;
}
*/

#endif // _PILAVT_H

