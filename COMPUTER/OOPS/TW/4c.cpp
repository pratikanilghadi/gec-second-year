/*Concept of stack unwinding*/
//Q 4C
#include<iostream>

using namespace std;

void fun1()
{
 cout<<"Inside fun1()"<<endl;
 throw 1;
}

void fun2()
{
 cout<<"Inside fun2()"<<endl;
 fun1();
}

void fun3()
{
 cout<<"Inside fun3()"<<endl;
 fun2();
}

int main()
{
 try
 {
  cout<<"Inside try block"<<endl;
  fun3();
 }
 catch(int i)
 {
  cout<<"Inside catch block"<<endl;
 }
 return 0;
}