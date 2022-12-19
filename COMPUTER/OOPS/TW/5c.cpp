/*Iterators with string classs*/
//Q 5C
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Enter a String with even string lenth: ";
    getline(cin,s);
    cout<<"Displaying string without iterators :"<<s;
    cout<<"\nDisplaying String using Iterator:";
    for(string::iterator itr =s.begin(); itr!= s.end() ; itr++)
    {
    	itr=itr+1;//points to next element
        cout<<*itr;
    }
}