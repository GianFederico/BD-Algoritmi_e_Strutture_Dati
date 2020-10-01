#ifndef _PILAV_H
#define _PILAV_H
#include "nodopv.h"
#include <iostream>
#include "pilav.h"
using namespace std;

const int MAXLUNGH=100;

template <class T>
class PilaV{
  friend void stampaPila(PilaV & L);

  public:
    PilaV();
    PilaV(int);
    ~PilaV();
    void create(int);
    bool empty() const;
    tipoelem read() const;
    void pop();
    void push(tipoelem);
  private:
    Nodo elementi[MAXLUNGH];
    int head;
  };


template <class T>
PilaV<T>::PilaV()
{
  create(MAXLUNGH);
}

template <class T>
PilaV<T>::PilaV(int dim)
{
  create(dim);
}

template <class T>
PilaV<T>::~PilaV()
{}

template <class T>
void PilaV<T>::create(int dim)
{
  for (int i=0;i<dim;i++)
    {
      elementi[i].setElemento(0);
    }
  head=0;
}

template <class T>
bool PilaV<T>::empty() const
  {
    return head==0;
  }

template <class T>
tipoelem PilaV<T>::read() const
{
  return (elementi[head-1].getElemento());
}

template <class T>
void PilaV<T>::pop()
{
  if (!empty())
    {
      head-=1;
    }
  else
    {
      cout<<"nessun elemento nella pila"<<endl;
    }
}

template <class T>
void PilaV<T>::push(tipoelem el)
{
  if (head==MAXLUNGH)
    {
      cout<<"raggiunta capacità massima della pila"<<endl;
    }
  else
    {
      elementi[head].setElemento(el);
      head++;
    }
}

template <class T>
void stampaPila(PilaV<T> & L)
{
  int i;
  for (i = 0; i< L.head; i++)
    cout << L.elementi[i] << " ";
}

#endif // _PILAV_H
