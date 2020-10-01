#include <iostream>
#include "../../realizzazioni/pila/pilavt/pilavt.h"
#include "../../realizzazioni/pila/pilav/pilav.h"
#include "../../realizzazioni/pila/pilav/nodopv.h"
#include "pilapt.h"
#include "nodoppt.h"

using namespace std;

void PROVA_PILAVT(){
    PilaVT<int> p=PilaVT<int>(10);

    if(p.empty())
        cout<<"vuota"<<endl;
    else cout<<"piena"<<endl;

    for (int i = 0; i<10; i++)
        p.push(i+1);

    cout<<p.read()<<endl;

    p.pop();
    p.pop();

    if(p.empty())
        cout<<"vuota"<<endl;
    else cout<<"piena"<<endl;

    cout<<p.read();
}

void PROVA_PILAV(){
    PilaV<int> p=PilaV<int>(10);

    if(p.empty())
        cout<<"vuota"<<endl;
    else cout<<"piena"<<endl;

    for (int i = 0; i<10; i++)
        p.push(i+1);

    cout<<p.read()<<endl;

    p.pop();
    p.pop();

    if(p.empty())
        cout<<"vuota"<<endl;
    else cout<<"piena"<<endl;

    cout<<p.read();
}

void PROVA_PILAPT(){
    PilaPT<int> p;

    if(p.empty())
        cout<<"vuota"<<endl;
    else cout<<"piena"<<endl;

    for (int i = 0; i<10; i++)
        p.push(i+1);

    cout<<p.top()<<endl;

    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();
    p.pop();

    cout<<p.top()<<"jjj"<<endl;

    if(p.empty())
        cout<<"vuota"<<endl;
    else cout<<"piena"<<endl;

    cout<<p.top();
}


int main()
{
    //PROVA_PILAVT();
    //PROVA_PILAV();

    PROVA_PILAPT();


    return 0;
}
