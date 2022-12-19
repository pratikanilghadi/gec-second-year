/*Telephone Directory for searching and updating contacts*/
//Q 3B
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

class telephone
{
public:
  int number;
  string name;
  
  void getdata()
  {
     cout<<"Enter name: ";
     getline(cin,name);
     cout<<"Enter number: ";
     cin>>number;
  }	
  
   void display()
  {
    cout<<"Name : "<<name<<"Number : "<<number<<endl;
  }
};

void search_n(int n, telephone t[])
{//searching by the name
   string s;
   cin.ignore();
   cout<<"Enter name to Search: ";
   getline(cin,s);
   ifstream fin;
   fin.open("Telephone.txt");
    int i;
   for(i=0;i<n;i++)
  {
    fin>>t[i].name>>t[i].number;
    if(t[i].name==s)
    {
      cout<<"Name : "<<t[i].name<<"\t Number: "<<t[i].number<<endl;
       break;
    }
 }
 if(i==n)
    cout<<"Not present\n";
}

void search_t(int n, telephone t[])
{//searching by ph no
   int num;
   cin.ignore();
   cout<<"Enter no. to Search: ";
   cin>>num;
   ifstream fin;
   fin.open("Telephone.txt");
   int i;
   for(i=0;i<n;i++)
  {
    fin>>t[i].name>>t[i].number;
    if(t[i].number==num)
   {
     cout<<"Name : "<<t[i].name<<"\t Number: "<<t[i].number<<endl;
     break;
   }
  }
    if(i==n)
    cout<<"Not present\n";
}

void update(int n,telephone t[])
{//updating the phone no.
  string s;
  cin.ignore();
  cout<<"Enter name to Update Details: ";
  getline(cin,s);
  ifstream fin;
  fin.open("Telephone Directory.txt");
  int i;
  for(i=0;i<n;i++)
 {
  fin>>t[i].name>>t[i].number;
  if(t[i].name==s)
  {
    cout<<"Enter new number to update: ";
   cin>>t[i].number;
   break;
  }
 }
 if(i==n)
    cout<<"Not present\n";
 fin.close();
 ofstream fout;
 fout.open("Telephone.txt");
 for(i=0;i<n;i++)
    fout<<setw(15)<<t[i].name<<setw(10)<<t[i].number<<endl;
 fout.close();
}

int main()
{
int n=2;int num;
telephone t[n];

ifstream fin;
  fin.open("Telephone.txt");
if(!fin)
 { 
 cout<<"Error!File doesn't exists";
 return 0;
 } 
 
int ch;
   do
 {
  cout<<"\n1.Search name\n2.Search no.\n3.Update number\n4.Exit\n";
  cin>>ch;
    switch(ch)
  {
     case 1:search_n(n,t);break;
     case 2:search_t(n,t);break;
     case 3:update(n,t);break;
     case 4:break;
     default:cout<<"Invalid input.\n";
   }
 }while(ch!=4);
return 0;
}