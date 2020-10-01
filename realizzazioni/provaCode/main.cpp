#include <iostream>
#include "../../realizzazioni/coda/codevt/codavt.h"
#include "codept.h"

using namespace std;

int PROVA_CODA_VT(){

  Coda<int> C(5);

  for(int i=0; i<5;i++){
    C.inCoda(i+1);
  }

  Coda<int> B=C;
  cout << ((B==C) ? "VERO" : "FALSO") << endl;
  B.fuoriCoda();
  cout << ((B==C) ? "VERO" : "FALSO") << endl;
  cout << B.leggiCoda() << endl;
  B.fuoriCoda();
  cout << C.leggiCoda() << endl;
  C.fuoriCoda();
  cout << C.leggiCoda() << endl;

    return 0;
}

int PROVA_CODA_PT(){
    CodaPT<int> c;

    c.push(11);

     cout<<c.top();
    return 0;
}


int main()
{
    //PROVA_CODA_VT();
    PROVA_CODA_PT();
    return 0;
}
