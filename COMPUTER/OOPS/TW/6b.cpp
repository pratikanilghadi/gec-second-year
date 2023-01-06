/*list container*/
//Q 6B
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> list1;

    list1.push_front(9);
    list1.push_front(8);
    list1.push_front(7);
    list1.push_back(6);
    list1.push_back(5);

    cout << "Original list: ";
    for (int x : list1)
    { cout << x << " "; }
    cout << endl;

    list<int> list2;
    list2.push_back(4);
    list2.push_back(3);
    list2.push_back(2);

    list1.splice(list1.end(), list2);

    cout << "After splice: ";
    for (int x : list1)
    { cout << x << " "; }
    cout << endl;
    
    list1.sort();

    cout << "After sort: ";
    for (int x : list1)
    { cout << x << " "; }
    cout << endl;

    list<int> list3;
    list3.push_back(10);
    list3.push_back(11);
    list3.push_back(12);

    list1.merge(list3);

    cout << "After merge: ";
    for (int x : list1)
    { cout << x << " "; }
    cout << endl;
    return 0;
}