#include<iostream>

using namespace std;

class media
{
 protected:
           char title[20];
           int sr_no;
           float price;

 public:
        virtual void display()=0;
        void getdata()
        {
         cout<<"\n Enter title: ";
         cin.getline(title,20);
         cout<<"Enter serial no: ";
         cin>>sr_no;
         cout<<"Enter price: ";
         cin>>price;
        }
};

class book:public media
{
 protected:
         int pages;
         int year;
         char publisher[20];

 public:
        void getbook()
        {
         cout<<"Enter total number of pages: ";
         cin>>pages;
         cout<<"Enter year of publication: ";
         cin>>year;
         fflush(stdin);
         cout<<"Enter publisher name: ";
         cin.getline(publisher,20);
        }

        void display()
        {
         cout<<"Title: "<<title;
         cout<<"\nSerial no: "<<sr_no;
         cout<<"\nPrice: "<<price;
         cout<<"\nTotal number of pages: "<<pages;
         cout<<"\nYear of publication: "<<year;
         cout<<"\nPublisher: "<<publisher;
        }
};

class tape:public media
{
 protected:int time;
           char artist[20];
           char manufacturer[20];

 public:
        void gettape()
        {
         cout<<"Enter time in minutes: ";
         cin>>time;
         fflush(stdin);
         cout<<"Enter artist: ";
         cin.getline(artist,20);
         fflush(stdin);
         cout<<"Enter manufacturer: ";
         cin.getline(manufacturer,20);
        }

        void display()
        {
         cout<<"\n\nTitle: "<<title;
         cout<<"\nSerial no: "<<sr_no;
         cout<<"\nPrice: "<<price;
         cout<<"\nTime in minutes: "<<time;
         cout<<"\nArtist: "<<artist;
         cout<<"\nManufacturer: "<<manufacturer;
        }
};

int main()
{
 int n1=0,n2=0;
 cout<<"Enter the Number of books: ";
 cin>>n1;

 cout<<"Enter the number of tapes: ";
 cin>>n2;

 media *m;
 book *b=new book[n1];
 tape *t=new tape[n2];

 for(int i=0;i<n1;i++)
 {
  cout<<"\nEnter details of book "<<i+1;
  b[i].getdata();
  b[i].getbook();
 }

 for(int i=0;i<n2;i++)
 {
  cout<<"\nEnter details of tape "<<i+1;
  t[i].getdata();
  t[i].gettape();
 }

 m=b;
 for(int i=0;i<n1;i++)
 {
  cout<<"\n\nDetails of book "<<i+1;
  m->display();
 }

 m=t;
 for(int i=0;i<n2;i++)
 {
  cout<<"\n\nDetails of tape "<<i+1;
  m->display();
 }
 return 0;
}
