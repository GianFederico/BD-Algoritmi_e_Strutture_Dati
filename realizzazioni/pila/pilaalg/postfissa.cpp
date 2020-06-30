#include <iostream>
#include <string>
#include <cstring>
#include "pilavt.h"

using namespace std;

int main(int argc, char *argv[]){
   char *a = argv[1]; int N = strlen(a);
   Pila<int> postf(N); int op1; int op2;
   bool inNumber = false;
   for (int i = 0; i < N; i++){
      if (a[i] == '+'){
         inNumber = false;
         op1 = postf.leggiPila(); postf.fuoriPila();
         op2 = postf.leggiPila(); postf.fuoriPila();
         postf.inPila(op1 + op2);
      } else if (a[i] == '*'){
         inNumber = false;
         op1 = postf.leggiPila(); postf.fuoriPila();
         op2 = postf.leggiPila(); postf.fuoriPila();
         postf.inPila(op1 * op2);
      } else if ((a[i] >= '0') && (a[i] <= '9')){
         if (inNumber) {
            op1 = postf.leggiPila(); postf.fuoriPila();
            postf.inPila(10 * op1 + (a[i]-'0'));
         } else {
            inNumber = true;
            postf.inPila(a[i]-'0');
         }
      } else {
         inNumber = false;
      }
   }
   cout << postf.leggiPila() << endl;
}
