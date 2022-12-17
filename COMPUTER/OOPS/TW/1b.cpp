#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class item
{
string name;
int code;
float cost;

public:
item(){}
item(string name1,int code1 ,float cost1)
{
name=name1;
code=code1;
cost=cost1;
}
void get_data()
{
 cout<<"Enter name: ";
 getchar();
 getline(cin,name);
 cout<<"Enter code: ";
 cin>>code;
 cout<<"Enter cost: ";
 cin>>cost;
}
void display(item l[],int i);
};

void item:: display(item l[],int i)
{
 cout.width(10);
 cout<<l[i].name;
 cout.width(10);
 cout<<l[i].code;
 cout.width(10);
 cout<<fixed<<setprecision(2)<<showpoint<<l[i].cost<<endl;
}

int main()
{
int n;
cout<<"Enter number of items: ";
cin>>n;
item a[n];
for(int i=0;i<n;i++)
{
 cout<<"\nEnter Details of item "<<i+1<<endl;
a[i].get_data();
}
cout.setf(ios::left,ios::adjustfield);
cout.fill('-');
cout.width(32);
cout<<""<<endl;
cout.fill(' ');
cout.width(10);
cout<<"Name";
cout.width(10);
cout<<"Code";
cout.width(10);
cout<<"Cost"<<endl;
cout.fill('-');
cout.width(32);
cout<<""<<endl;
cout.fill(' ');
for(int i=0;i<n;i++)
{
a[i].display(a,i);
}
return 0;
}
