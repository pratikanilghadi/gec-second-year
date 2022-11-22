//Experiment 4B
#include<iostream>

using namespace std;

class num 
{
 private: int a;

 public:
        num(int n)//constructor
        { a=n; }

        void output()
        { cout<<a<<endl; }

        friend num operator+ (int i,num &obj) //overloading +
        { return (i+obj.a); }

        num operator* (num &obj) //overloading *
        { return (a*obj.a); }

        friend num operator- (num &obj,int i) //overloading -
        { return (obj.a-i); }
};

int main()
{
 int number,option;;
 cout<<"Enter value of x : ";
 cin>>number;
 num x(number);

 cout<<"Enter the value of y: ";
 cin>>number;
 num y(number);

 while(1)
 {
  cout<<"\n1.x=5+y\n";
  cout<<"2.x=x*y\n";
  cout<<"3.x=y-5\n";
  cout<<"4.exit\n";
  cout<<"Enter your choice : ";
  cin>>option;

  switch(option)
  {
   case 1:x=5+y;
          cout<<"\nThe value of x=5+y is ";
          x.output();
          break;

   case 2:x=x*y;
          cout<<"\nThe value of x=x*y is ";
          x.output();
          break;
   
   case 3:x=y-5;
          cout<<"\nThe value of x=y-5 is ";
          x.output();
          break;

   case 4:exit(1);

   default:cout<<"Invalid input\n";
  }
 }
 return 0;
}