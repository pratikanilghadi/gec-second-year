#include<iostream>
#include<string>

using namespace std;

class bill
{
 private:
         string name;
         int unit;
         float cost;

 public:
        bill()
        {
         cost=50;
        }
        void input();
        void calculation();
        void display();
};

void bill :: input()
{
  cout<<"Name: ";
  cin>>name;
  cout<<"Total units consumed: ";
  cin>>unit;
}

void bill :: calculation()
{
 if(unit<=100)
 {
  cost=cost+(unit*0.6);
 }
 else if(unit>100 && unit<=300)
 {
  cost =cost+60+((unit-100)*0.8);
 }
 else
 {
  cost=cost+220+((unit-300)*0.9);
 }
 if(cost>300)
 {
  cost =cost+(cost*0.15);
 }
}

void bill::display()
{
 cout<<"Name: "<<name<<endl;
 cout<<"units consumed: "<<unit<<endl;
 cout<<"Total Bill Amount: "<<cost<<"Rs"<<endl;

}

int main()
{
  int n;
  cout<<"Enter total number of customers: ";
  cin>>n;
  bill b[n];
  for(int i=0;i<n;i++)
  {
   cout<<"Enter details of customer "<<i+1<<endl;
   b[i].input();
   b[i].calculation();
  }

  for(int i=0;i<n;i++)
  {
   cout<<endl<<"Bill of Customer "<<i+1<<" is :"<<endl;
   b[i].display(); 
  }
  return 0;
}