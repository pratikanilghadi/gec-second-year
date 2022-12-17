/*write a program that throws an arithmatic exception as and when a number input is greater than 9999*/
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
  {
   throw n;
  }
  else
  {
   cout<<"Number is: "<<n;
  }
 }
 catch(int n)
 {
  cout<<"Exception Caught !!!"<<endl<<"Number is greater than 9999";
 }
}