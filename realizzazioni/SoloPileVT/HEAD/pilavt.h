#ifndef PILAVT_H
#define PILAVT_H

#include <iostream>

using namespace std;


template <class T>
class PilaVT{
  public:
    typedef T tipoelem;

    PilaVT();
    PilaVT(int);
    ~PilaVT();
    void create();
    bool empty() const;
    tipoelem read() const;
    void pop();
    void push(tipoelem);
  private:
    tipoelem *elementi;
    int MAXLUNGH;
    int head;
  };

template <class T>
PilaVT<T>::PilaVT()
{
  elementi = new tipoelem[100]; // 100 dimensione standard della pila
  MAXLUNGH = 100;
  create();
}

template <class T>
PilaVT<T>::PilaVT(int N)
{
  elementi = new tipoelem[N]; // dimensione N della pila
  MAXLUNGH = N;
  create();
}

template <class T>
PilaVT<T>::~PilaVT()
{
  delete[] elementi;
};

template <class T>
void PilaVT<T>::create()
{
  head=0;
}

template <class T>
bool PilaVT<T>::empty() const
  {
    return (head==0);
  }

template <class T>
T PilaVT<T>::read() const
  {
    return elementi[head-1];
  }

template <class T>
void PilaVT<T>::pop()
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
void PilaVT<T>::push(tipoelem el)
{
  if (head==MAXLUNGH)
    {
      cout<<"raggiunta capacità massima della pila"<<endl;
    }
  else
    {
      elementi[head]=el;
      head++;
    }
}

#endif // _PILAVT_H
