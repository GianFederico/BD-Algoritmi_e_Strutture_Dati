#include <iostream>
#include "pilavt.h"

using namespace std;

enum piolo { origine, intermedio, destinazione };

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
  if (n==1)
    muovisorg_a_destin(orig, dest);
  else {
    move(n-1, orig, dest, inter);
    muovisorg_a_destin(orig, dest);
    move(n-1, inter, orig, dest);
  }
}

int main () {
  int numerodischi;
  cin >> numerodischi;
  cout << "per " << numerodischi << " dischi i movimenti richiesti sono:" << endl;
  move(numerodischi, origine, intermedio, destinazione);
  return 0;
}
