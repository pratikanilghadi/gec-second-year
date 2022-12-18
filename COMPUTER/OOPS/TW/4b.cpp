/*wite a c++ template function , called exchange () that accepts two arguments of generic tyoe and swap their contents*/

#include<iostream>

using namespace std;
template<class T>
void exchange(T &x,T &y)
{
 T temp=x;
 x=y;
 y=temp;
}

void fun(int a,int b)
{
 cout<<"Before swap: a="<<a<<" b="<<b<<endl;
 exchange(a,b);
 cout<<"After swap:  a="<<a<<" b="<<b<<endl;
 exchange(a,b);
}

int main()
{
 int a=0,b=0;
 cout<<"Enter first number: ";
 cin>>a;
 cout<<"Enter second number: ";
 cin>>b;
 fun(a,b);
 return 0;
}