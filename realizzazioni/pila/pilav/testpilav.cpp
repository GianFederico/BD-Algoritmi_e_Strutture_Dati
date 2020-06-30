#include "pilav.h"
#include <iostream>

using namespace std;

int main() {
  Pila p=Pila();
  p.creaPila();
  cout << "in pila 3" << endl;
  p.inPila(3);
  cout << "in pila 5" << endl;
  p.inPila(5);
  cout << "in pila 2" << endl;
  p.inPila(2);
  cout << "leggo pila " << p.leggiPila() << endl;
  cout << "fuori pila" << endl;
  p.fuoriPila();
  cout << "leggo pila " << p.leggiPila() << endl;
  cout << "pila vuota? " << ((p.pilaVuota()==0) ? "NO" : "SI") << endl;
  cout << "fuori pila" << endl;
  p.fuoriPila();
  cout << "fuori pila" << endl;
  p.fuoriPila();
  cout << "pila vuota? " << ((p.pilaVuota()==0) ? "NO" : "SI") << endl;
}
