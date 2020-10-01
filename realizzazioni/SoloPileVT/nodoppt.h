#ifndef NODOPPT_H_INCLUDED
#define NODOPPT_H_INCLUDED

using namespace std;


template <class T>
class NodoPT{
typedef T tipoelem;
  public:

    NodoPT();
    NodoPT(tipoelem);
    ~NodoPT();

    void setElemento(tipoelem);
    tipoelem getElemento() const;
    void setPrev(NodoPT<T>*);
    NodoPT<T>* getPrev();
    bool operator ==(NodoPT<T> &);

  private:
    tipoelem elemento; //etichetta
    NodoPT<T>* prev;
  };


template <class T>
NodoPT<T>::NodoPT()
{
    prev=nullptr;
}
template <class T>
NodoPT<T>::~NodoPT()
{
    delete(prev);
}

template <class T>
NodoPT<T>::NodoPT(tipoelem label)
{
  elemento=label;
}

template <class T>
void NodoPT<T>::setElemento(tipoelem label)
{
  elemento=label;
}

template <class T>
T NodoPT<T>::getElemento() const
{
    return elemento;
}

template <class T>
void NodoPT<T>::setPrev(NodoPT<T>* ptr)
{
prev=ptr;
}

template <class T>
NodoPT<T>* NodoPT<T>::getPrev(){
    return prev;
}

template <class T>
bool NodoPT<T>::operator==(NodoPT & n)
{
  return (getElemento() == n.getElemento());
}

template <class T>
ostream & operator<<(ostream & out, const NodoPT<T> & nodo)
{
  return out << nodo.getElemento();
}



#endif // NodoPPT_H_INCLUDED
