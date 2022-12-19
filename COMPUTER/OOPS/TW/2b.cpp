/*Virtual functions*/
//Q 2B
#include<iostream>
using namespace std;

class Base
{
	public:
		void display()
		{
			cout<<"Display base.";
		}
		virtual void show()
		{cout<<"\nShow base.\n";}
};

class Derived: public Base
{
	public:
		void display()
		{	cout<<"Display derived.\n";	}
		void show()
		{	cout<<"\nShow derived.";	}
};

int main()
{
	Base B;
	Derived D;//object of derived class
	Base *ptr;//ptr of base class
	ptr = &B;
	cout<<"In base class:\n";
	ptr->display();
	ptr->show();
	cout<<"\nIn derived class:\n";
	ptr = &D;
	ptr->display();
	ptr->show();
	return 0;
}