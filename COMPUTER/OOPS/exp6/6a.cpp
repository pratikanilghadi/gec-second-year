#include<iostream>

using namespace std;

class base
{
 public:
        void display()
        {
         cout<<"\nDisplay base.";
        }
        virtual void show()
        {
         cout<<"\nShow base.";
        }
};

class derived:public base
{
 public: 
        void display()
        {
         cout<<"\nDisplay derived.";
        }
        void show()
        {
         cout<<"\nShow derived.";
        }
};

int main()
{
 base b;
 derived d;
 base *p;

 cout<<"\np points to base object.";
 p=&b;
 p->display();
 p->show();

 cout<<"\np points to derived object.";
 p=&d;
 p->display();
 p->show();
 return 0;
}