#include <iostream>
#include "../../realizzazioni/alberi/TreeList.h"
#include "../../realizzazioni/alberi/treelink/TreeLink.h"

using namespace std;

int PROVA_TREELIST(){

    TreeList<char> Tree;

    TreeList<char>::node n;
    Tree.insRoot();
    Tree.writeNode(Tree.root(),'a');
    Tree.insFirst(Tree.root(), 'b');
    Tree.insFirst(Tree.root(), 'c');

    n = Tree.root();
    n = Tree.firstChild(n);
    Tree.ins(n, 'd');

    n = Tree.root();
    n = Tree.firstChild(n);
    Tree.insFirst(n, 'e');
    Tree.insFirst(n, 'f');

    Tree.print();
    cout<<"Primo albero"<<endl<<endl;

    TreeList<char> Alb;
    Alb.insRoot();
    Alb.writeNode(Alb.root(),'w');

    Alb.insFirst(Alb.root(), 'x');
    Alb.insFirst(Alb.root(), 'y');

    n = Alb.root();
    n = Alb.firstChild(n);
    Alb.insFirst(n, 'z');
    Alb.insFirst(n, 'g');
    Alb.insFirst(n, 'h');
    Alb.insFirst(n, 'i');
    Alb.print();
    cout<<"Secondo albero"<<endl<<endl;

    Tree.insSubTree(2, Alb);
    Tree.print();
    cout<<"Alberi connessi"<<endl;

    /*n = Tree.root();
    n = Tree.firstChild(n);
    Tree.removeSubTree(n);
    Tree.print();*/

    return 0;
}

int PROVA_TREELINK(){

    TreeLink<char> tree;
    TreeLink<char>::node n;

    tree.insRoot('a');

    tree.insFirst(tree.root(), 'b');
    tree.insFirst(tree.root(), 'c');
    tree.ins(tree.firstChild(tree.root()),'d');

    tree.insFirst(tree.firstChild(tree.root()), 'e');
    tree.insFirst(tree.firstChild(tree.root()), 'f');

    tree.print(tree.root());



    TreeLink<char> Alb;
    Alb.insRoot('w');

    Alb.insFirst(Alb.root(), 'x');
    Alb.insFirst(Alb.root(), 'y');

    n = Alb.root();
    n = Alb.firstChild(n);
    Alb.insFirst(n, 'z');
    cout<<endl;

    //tree.insFirstSubTree(tree.firstChild(tree.root()),Alb);
    tree.insSubTree(tree.firstChild(tree.root()),Alb);
    tree.print(tree.root());


    cout << "remove c" << endl;
    tree.removeSubTree(tree.firstChild(tree.root()));
    tree.print(tree.root());
    return 0;
}


int main()
{
    //PROVA_TREELIST();
    PROVA_TREELINK();
    return 0;
}
