#include "../../realizzazioni/codeprior/codap.h"
#include <iostream>

using namespace std;

int PROVA_PRIORICODE () {
  CodaP < int > C;

  C.inserisci (1);
  C.inserisci (12);
  C.inserisci (19);
  C.inserisci (7);
  cout << "[1,12,19,7]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
  C.inserisci (0);
  C.inserisci (11);
  cout << "[12,19,7,0,11]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
  C.inserisci (5);
  C.inserisci (21);
  C.inserisci (18);
  cout << "[12,19,7,11,5,21,18]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
  C.inserisci (3);
  cout << "[12,19,7,11,21,18,3]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();

}



int main()
{
    PROVA_PRIORICODE();
    return 0;
}
