#include<iostream>

using namespace std;

inline void multiply();
inline void divide();

class XYZ;
class ABC
{
 int x;
 public:
        void input();
        friend void swap(ABC &,XYZ &);
};

class XYZ 
{
 int y;
 public:
        void input();
        friend void swap(ABC &,XYZ &);
};

void ABC ::input()
{
 cout<<"Enter 1st number: ";
 cin>>x;
}

void XYZ ::input()
{
 cout<<"Enter second number: ";
 cin>>y;
}
int main()
{
  ABC a;
  a.input();
  XYZ b;
  b.input();
  swap(a,b);
  multiply();
  divide();
  return 0;
}

void swap(ABC &a,XYZ &b)
{
 int temp;
 cout<<"The numbers before swapping are "<<a.x<<" and "<<b.y<<endl;
 temp=a.x;
 a.x=b.y;
 b.y=temp;
 cout<<"The numbers after swapping are "<<a.x<<" and "<<b.y<<endl;
}

inline void multiply()
{
 int x,y;
 cout<<"\nEnter the two numbers to be multiplied: ";
	cin>>x>>y;
	cout<<"The product is: "<<x*y;
}

inline void divide()
{
	float x, y;
	cout<<"\n\nEnter the two numbers to be divided: ";
	cin>>x>>y;
	cout<<"The quotient is: "<<x/y;
}