#include<iostream>
#include<conio.h>

using namespace std;

void add(int a,int b);
void add(float x,float y);

int main()
{
 int op,a,b;
 float x,y;
 while(1)
 {
  cout<<"1-Adding 2 integers "<<endl;
  cout<<"2-Adding 2 floats "<<endl;
  cout<<"3-exit"<<endl;
  cin>>op;
  switch(op)
  {
   case 1:cout<<"Enter value of a: ";
          cin>>a;
          cout<<"Enter value of b: ";
          cin>>b;
          add(a,b);
          break;

   case 2:cout<<"Enter value of x: ";
          cin>>x;
          cout<<"Enter value of y: ";
          cin>>y;
          add(x,y);
          break;

   case 3:exit(1);

   default:cout<<"invalid input"<<endl;
 }
 }
}

void add(int a,int b)
{
 cout<<" a+b= "<<a+b<<endl;
}

void add(float x,float y)
{
 cout<<" x+y= "<<x+y<<endl;
}