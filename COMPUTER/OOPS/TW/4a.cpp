/*Write a program thatthrows an arithmatic exception as and when a numberinput is greater than 9999*/
//Q 4A
#include<iostream>

using namespace std;

int main()
{
 int n;
 cout<<"Enter a number: ";
 cin>>n;
 try
 {
  if(n>9999)
  { throw n; }
  else
  { cout<<"Number is: "<<n; }
 }
 catch(int n)
 { cout<<"Exception Caught !!!"<<endl<<"Number is greater than 9999"; }
}