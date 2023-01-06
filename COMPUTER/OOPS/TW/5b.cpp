/*String class function*/
//Q 5B
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cout<<"Enter a String of len 10\n";
    cin>>s;
    cout<<"\nSlicing the String [1-5]\n"<<s.substr(1,5)<<"\n";
    cout<<"\nSearching Element 'a' in the string\n"<<s.find('a')<<"\n";
    cout<<"\nCapacity of String\n"<<s.capacity()<<"\n";
    string str = "GEC";
    cout<<"\nInsert New String\n"<<s.insert(6,str)<<"\n";
}