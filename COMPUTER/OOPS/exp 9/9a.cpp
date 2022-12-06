#include<iostream>

using namespace std;

void divide(int a,int b)
{
 try
 {
  if(b==0)
  {
   throw b;
  }
  else
  {
   cout<<"Result = "<<a/b<<endl;
  }
  }
  catch(int)
  {
   cout<<"Cought int inside Divide function\n";
   throw;  //rethrowing the exception
  }
}
int main()
{
 int x,y;
 cout<<"Enter two numbers : ";
 cin>>x>>y;
 try
 {
  divide(x,y);
 }
 catch(int)
 {
  cout<<"Exception Caught in main\n"<<"Division by zero not possible"<<endl;
 }
}