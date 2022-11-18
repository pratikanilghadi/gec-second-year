#include<iostream>

using namespace std;

class number
{
    private:
            int a;
    public:
           number() //constructor
           {a=0;}

           number operator ++() //prefix increment
           {
            number temp;
            temp.a=++a;
            return temp;
           }

           number operator ++(int) //postfix increment
           {
            number temp;
            temp.a=a++;
            return temp;
           }

           number operator --() //prefix decrement
           {
            number temp;
            temp.a=--a;
            return temp;
           }

           number operator --(int) //postfix decrement
           {
            number temp;
            temp.a=a--;
            return temp;
           }

           void display()
           { cout<<" = "<<a<<endl;}
};

int main()
{
    number Ob1, Ob2;
    cout<<"\nBefore increment"<<endl;
    cout<<"Ob1";
    Ob1.display();
    cout<<"Ob2";
    Ob2.display();

    cout<<"\nAfter prefix increment"<<endl;
    Ob1=++Ob2;
    cout<<"Ob1";
    Ob1.display();
    cout<<"Ob2";
    Ob2.display();

    cout<<"\nAfter postfix increment "<<endl;
    Ob1=Ob2++;
    cout<<"Ob1";
    Ob1.display();
    cout<<"Ob2";
    Ob2.display();

    cout<<"\nBefore decrement"<<endl;
    cout<<"Ob1";
    Ob1.display();
    cout<<"Ob2";
    Ob2.display();

    cout<<"\nAfter prefix decrement "<<endl;
    Ob1=--Ob2;
    cout<<"Ob1";
    Ob1.display();
    cout<<"Ob2";
    Ob2.display();

    cout<<"\nAfter postfix decrement "<<endl;
    Ob1=Ob2--;
    cout<<"Ob1";
    Ob1.display();
    cout<<"Ob2";
    Ob2.display();

    return 0;
}