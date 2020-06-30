#include <iostream>
#include "pilavt.h"

using namespace std;

enum piolo { origine, intermedio, destinazione };

struct stato {
  int numerodischi;
	piolo	piolorig;
  piolo piolodest;
  piolo pioloaus;
	int ritorno;
};

void printpole(piolo p) {
  if (p==origine)
    cout << " origine ";
  else if (p==intermedio)
    cout << " intermedio ";
  else
    cout << " destinazione ";
}

void muovisorg_a_destin(piolo o, piolo d) {
  cout << "muovi un disco da";
  printpole(o);
  cout << "a";
  printpole(d);
  cout << endl;
}

void move(int n, piolo orig, piolo inter, piolo dest) {
  Pila<stato> stack;
  piolo temp;
  stato s;
  stack.creaPila();
  passo1:
    if (n==1) {
      muovisorg_a_destin(orig, dest);
      goto passo3;
    }
    s.numerodischi = n;
    s.piolorig  = orig;
    s.pioloaus = inter;
    s.piolodest = dest;
    s.ritorno = 2;
    stack.inPila(s);
    n--;
    temp = dest;
    dest = inter;
    inter = temp;
    goto passo1;
  passo2:
    muovisorg_a_destin(orig, dest);
    s.numerodischi = n;
    s.piolorig = orig;
    s.pioloaus = inter;
    s.piolodest = dest;
    s.ritorno = 3;
    stack.inPila(s);
    n--;
    temp = orig;
    orig = inter;
    inter = temp;
    goto passo1;
  passo3:
    if (!stack.pilaVuota()) {
        stato sp = stack.leggiPila();
        stack.fuoriPila();
        n = sp.numerodischi;
        orig = sp.piolorig;
        dest = sp.piolodest;
        inter = sp.pioloaus;
        switch (sp.ritorno) {
          case 2: goto passo2;
          case 3: goto passo3;
        }
    }
}

int main() {
  int numerodischi;
  cin >> numerodischi;
  cout << "per " << numerodischi << " dischi i movimenti richiesti sono:" << endl;
  move(numerodischi, origine, intermedio, destinazione);
  return 0;
}
