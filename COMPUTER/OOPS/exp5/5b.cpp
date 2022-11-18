#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class student
{
 protected:
           string name;
           int roll;
           string branch;

 public:
        void details()
        {
         cout<<"\nEnter the name of the student: ";
         cin>>name;

         cout<<"Enter the roll number of the student: ";
         cin>>roll;

         cout<<"Enter the branch of the student: ";
         cin>>branch;
        }

        void display()
        {
         cout<<endl<<setw(20)<<"**RESULT**"<<endl;
         cout<<"Name: "<<name<<endl;
         cout<<"Roll number: "<<roll<<endl;
         cout<<"Branch: "<<branch<<endl;
        }
};

class sem1:virtual public student
{
 protected:
           int maths;
           int physics;
           int chem;

 public:
        void sem1_marks()
        {
         cout<<"Enter the marks in maths: ";
         cin>>maths;
         cout<<"Enter the marks in physics: ";
         cin>>physics;
         cout<<"Enter the marks in chemistry: ";
         cin>>chem;
        }
};

class sem2:virtual public student
{
 protected:
           int OOPs;
           int co;
           int ds;

 public:
        void sem2_marks()
        {
         cout<<"Enter the marks in OOPs: ";
         cin>>OOPs;
         cout<<"Enter the marks in CO: ";
         cin>>co;
         cout<<"Enter the marks in ds: ";
         cin>>ds;
        }
};

class sports:virtual public student
{
 protected:
           int sports;

 public:
        void sports_marks()
        {
         cout<<"Enter the score in sports: ";
         cin>>sports;
        }
};

class result:public sem1,public sem2,public sports
{
 private:int total;
         float percentage;

 public:
        void display_result()
        {
         total=maths+physics+chem+OOPs+co+ds;
         percentage=total/6;
         cout<<"Total marks of all the subjects: "<<total<<"/600"<<endl;
         cout<<"Sports marks :"<<sports<<"/10"<<endl;
         cout<<"Percentage: "<<percentage<<"%"<<endl;
         if(percentage<40)
         {
          cout<<"Student FAILS"<<endl;
         }
         else if(percentage>=40 && percentage<60)
         {
          cout<<"Student gets SECOND CLASS"<<endl;
         }
         else if(percentage>=60 && percentage<75)
         {
          cout<<"Student gets FIRST CLASS"<<endl;
         }
         else
         {
          cout<<"Student gets DISTINCTION"<<endl;
         }
        }
};

int main()
{
 int i,n;
 cout<<"Enter the number of students: ";
 cin>>n;
 result *r;
 r=new result[n];
 for(int i=0;i<n;i++)
 {
  r[i].details();
  r[i].sem1_marks();
  r[i].sem2_marks();
  r[i].sports_marks();
  r[i].display();
  r[i].display_result();
 }      
 return 0; 
}