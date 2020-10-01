#include <iostream>
#include "../../realizzazioni/liste/linked_list/linear_list.h"
#include "../../realizzazioni/liste/linked_list/linked_list.h"
#include "../../realizzazioni/liste/linked_list/single_linked_list.h"
#include "../../realizzazioni/liste/list_vector/list_vector.h"

using namespace std;


int  PROVA_LINKED_LIST(){
  Linked_list<int> list1, list2;
  Linked_list<int>::position iter;

	int x;

	/* inserting three elements into the list list1 */
	x = 1;
  list1.insert(x, list1.begin());
	x = 2;
  list1.insert(x, list1.begin());
	x = 3;
  list1.insert(x, list1.begin());
	x = 4;
  list1.insert(x, list1.begin());

	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */


	list2 = list1;
	/* visualizing the list list2 */
	cout << "After list2=list1, list2="; cout << list2;

	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	/* erasing the first element from the list list2 */
	list2.erase(list2.begin());
	/* visualizing the list list2 */
	cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;


    cout<<list1.size()<<endl;

        list1.push_front(18);
    cout<<list1;
    cout<<list1.size()<<endl;

        list1.push_back(20);
    cout<<list1;
    cout<<list1.size()<<endl;

        list1.pop_back();
    cout<<list1;
    cout<<list1.size()<<endl;

        list1.pop_front();
    cout<<list1;
    cout<<list1.size()<<endl;

    //cout<<list1.read(list1.previous(list1.last()))<< endl;


    cout<<list1.read(list1.intToPos(2))<<"aaa"<<endl;

    list1.write(7, list1.intToPos(2));
    cout<<list1<<endl;
    cout<<list1.read(list1.intToPos(10))<<"yyy"<<endl;

    cout<<list1.read(list1.next(list1.intToPos(6)))<<"bbb"<<endl;

    cout<<list1.read(list1.previous(list1.begin()))<<endl;

    cout<<list1;

    if (list1.end(list1.next(list1.intToPos(3))))
        cout<<"posizione corrispondente a fine lista";

    if (list1.end(list1.intToPos(6)))
        cout<<"aaaaaaaaa";


}

int  PROVA_SINGLE_LINKED_LIST(){
  Single_Linked_list<int> list1, list2;

	/* inserting three elements into the list list1 */
  list1.insert(1, list1.begin());
  list1.insert(2, list1.begin());
  list1.insert(3, list1.begin());
  list1.insert(4, list1.begin());

	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */


	list2 = list1;
	/* visualizing the list list2 */
	cout << "After list2=list1, list2="; cout << list2;

  Single_Linked_list<int> list3(list1);
  cout << "After list3(list1), list3="; cout << list3;

	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	/* erasing the first element from the list list2 */
	list2.erase(list2.begin());
	/* visualizing the list list2 */
	cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

    cout<<list1.size()<<endl;

        list1.push_front(18);
    cout<<list1;
    cout<<list1.size()<<endl;

        list1.push_back(20);
    cout<<list1;
    cout<<list1.size()<<endl;

        list1.pop_back();
    cout<<list1;
    cout<<list1.size()<<endl;

        list1.pop_front();
    cout<<list1;
    cout<<list1.size()<<endl;



  return 0;


}

int  PROVA_LIST_VECTOR(){
  List_vector<int> list1, list2;
  List_vector<int>::position iter;

	int x;

	/* inserting three elements into the list list1 */
	x = 1;
  list1.insert(x, list1.begin());
	x = 2;
  list1.insert(x, list1.begin());
	x = 3;
  list1.insert(x, list1.begin());
	x = 4;
  list1.insert(x, list1.begin());

	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */
	list2 = list1;
	/* visualizing the list list2 */
	cout << "After list2=list1, list2="; cout << list2;

	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	/* erasing the first element from the list list2 */
	list2.erase(list2.begin());
	/* visualizing the list list2 */
	cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;


    list1.push_back(9);
    cout<<list1;
    cout<<list1.size()<<endl;

    list1.clear();
    cout<<list1;

}


void trasforma(List_vector<int>& list1, int x){
    List_vector<int>::position p;
    p=list1.begin();

    while(!list1.end(p)){
        if(list1.read(p)%2==0)
            list1.write(list1.read(p)+x, p);
        p = list1.next(p);
    }
    cout<<endl<<list1;
}


int main()
{
    //PROVA_LINKED_LIST();
    //PROVA_SINGLE_LINKED_LIST();
    //PROVA_LIST_VECTOR();

    List_vector<int> list1;
    Linked_list<int>::position p;


    int x = 6;
  list1.insert(x, list1.begin());
    x = 5;
  list1.insert(x, list1.begin());
	x = 4;
  list1.insert(x, list1.begin());
	x = 2;
  list1.insert(x, list1.begin());
  	x = 7;
  list1.insert(x, list1.begin());
	x = 1;
  list1.insert(x, list1.begin());

  trasforma(list1, 3);


}
