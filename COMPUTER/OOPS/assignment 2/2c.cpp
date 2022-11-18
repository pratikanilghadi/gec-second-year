#include<iostream>

using namespace std;

class DB;
class DM
{
 float m,cm;

 public:
        void input();
        friend void sum(DM &,DB &);
        void display();
};

class DB
{
 float inch,feet;

 public:
        void input();
        friend void sum(DM &,DB &);
        void display();
};

void DM :: input()
{
 cout<<"Enter distance in meter: ";
 cin>>m;
 cout<<"Enter distance in centimeter: ";
 cin>>cm;
}

void DB :: input()
{
 cout<<"Enter distance in feet: ";
 cin>>feet;
 cout<<"Enter distance in inch: ";
 cin>>inch;
}

void sum(DM &a,DB &b)
{
 int op;
 cout<<"1-meter-centimeter\n";
 cout<<"2-feet-inch\n";
 cout<<"Enter your choice : ";
 cin>>op;
 if(op==1)
 {
  DM d;
  int i=(a.m*100+a.cm+b.feet*30.48+b.inch*2.54);
  if(i>=100)
  {
   d.m=i/100;
   d.cm=i%100;
  }
  else
  {
   d.m=0;
   d.cm=i;
  }
  d.display();
 }
 else
 {
  DB d;
  int j=(a.m*39.37+a.cm*0.3937+b.feet*12+b.inch);
  if(j>=12)
  {
   d.feet=j/12;
   d.inch=j%12;
  }
  else
  {
   d.feet=0;
   d.inch=j;
  }
  d.display();
 }
}

void DM :: display()
{
 cout<<"The Total Distance is: ";
 cout<< m <<" meters and "<< cm <<" centimters "<<endl;
}

void DB :: display()
{
 cout<<"The Total Distance is: ";
 cout<< feet <<" feet and "<< inch <<" inch "<<endl;
}

int main()
{
 DM a;
 DB b;
 a.input();
 b.input();
 sum(a,b);
 return 0;
}