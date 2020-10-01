#include <iostream>
#include "../../realizzazioni/dizionari/hash_table.h"

#define MAXHASH 20

using namespace std;


class Histogram{



public:
    Histogram(){       //costruttore
       HashTable<int,int> diz(MAXHASH);
    }

    void add(int v){
        diz.find(v)->second++;
    }

    void remove(int v){
        diz.find(v)->second--;
    }

    int mode(){
        int mode = 0;
        for (int i = 0; i<diz.size(); i++)
            if (mode < diz.find(i)->second)
                mode = diz.find(i)->second;
        return mode;
    }


    double mean(){
        double mean = 0;
        for (int i = 0; i<diz.size(); i++)
            mean = mean + diz.find(i)->second;
        mean = mean / diz.size();
        return mean;
    }

    void print(){
        for (int i = 0; i<diz.size(); i++){
            cout<<diz.find(i)->first<<" ";
            int j, k;
            for (j = 0; j<diz.find(i)->second; j++)
                cout<<"*";
            cout<<endl;
        }
    }

    HashTable<int, int> getDiz(){
        return diz;
    }


private:
    HashTable<int,int> diz;
};


void ProvaHash(){
  HashTable<int,int> t(10);
  cout << " size " << t.size() << endl;
  struct Entry<int,int> e1;
  e1.first=1;
  e1.second=74654;
  t.insert(e1);
  e1.first=2;
  e1.second=666555;
  t.insert(e1);
  e1.first=3;
  e1.second=987654;
  t.insert(e1);
  e1.first=1;
  e1.second=999999;
  t.insert(e1);
  e1.first=1;
  e1.second=222222;
  t.insert(e1);

  if (t.find(2)!=NULL)
  cout << t.find(2)->second << endl;
  else cout<<"fuck u";

  t.modify(2, 768758);
  if (t.find(2)!=NULL)
  cout << t.find(2)->second << endl;
  else cout<<"fuck u";

  cout << " size " << t.size() << endl;

  /*struct Entry<string,string> e2;
  e2.first="rossi";
  e2.second="marco";
  t.insert(e2);
  cout << t.find("rossi")->second << endl;*/

}

int main() {
    //Histogram hist = Histogram();
    HashTable<int,int> diz(20);
    struct Entry<int,int> e;

        /*e.first = 1;
        e.second = 0;
        diz.insert(e);
        e.first = 2;
        e.second = 0;
        diz.insert(e);
        e.first = 4;
        e.second = 0;
        diz.insert(e);
        e.first = 5;
        e.second = 0;
        diz.insert(e);*/


    int i[] = {1, 2, 4, 1, 4, 5, 2, 5, 4, 1, 4, 1, 2, 2, 3, 5, 7};
    int k = 0;

    //cout<<hist.getDiz().find(2)->second;

    //hist.getDiz().find(1)->first=10;

    //cout<<hist.getDiz().find(1)->first;

    /*for (int j = 0; j<sizeof(i); j++){
        for (int k = 0; k<20; k++)
       if (i[j] == hist.getDiz().find(k)->first){
                hist.add(k);
            } else {
                e.first = i[j];
                e.second = 1;
                hist.getDiz().insert(e);
            }
     }*/
     int c;
     for(int s=0;s<40;s++)
    {
        if(i[s]!='\0')
            c++;
        else break;
    }

    for (int j = 0; j<c; j++){
            if (diz.find(i[j]) != NULL)
                if (i[j] == diz.find(i[j])->first){
                    diz.find(i[j])->second++;
                }
           if (diz.find(i[j]) == NULL){
                    e.first = i[j];
                    e.second = 1;
                    diz.insert(e);
           }
    }

    for (int l = 0; l<20; l++){
            if (diz.find(l) != NULL){
                cout<<diz.find(l)->first<<" ";
                for (int j = 0; j<diz.find(l)->second; j++)
                    cout<<"*";
                cout<<endl;
            }
        }


    //hist.print();


    //ProvaHash();

    return 0;

}
