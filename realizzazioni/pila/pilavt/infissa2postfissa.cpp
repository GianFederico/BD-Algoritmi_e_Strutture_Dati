#include <iostream>
#include <string>
#include <cstring>
#include "pilavt.h"

using namespace std;

int main(int argc, char *argv[]) {
  char *a = argv[1]; int N = strlen(a);
  Pila<char> operatori(N);
  for (int i = 0; i < N; i++){
      if (a[i] == ')') {
        cout << operatori.leggiPila() << " ";
        operatori.fuoriPila();
      } else if ((a[i] == '+') || (a[i] == '*'))
        operatori.inPila(a[i]);
      else if ((a[i] >= '0') && (a[i] <= '9'))
        cout << a[i] << " ";
   }
   cout << endl;
}
