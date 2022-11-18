//Experiment 4D
#include<iostream>
#include<cstring>

using namespace std;

class str
{
 private: char s[30];

 public:
        void input()
        { gets(s);}

        void display()
        { cout<<s<<endl;}

        str operator + (str &a) //overloading + operator 
        {
         str b;
         strcat(s,a.s);
         strcpy(b.s,s);
         return b;
        }

        int operator >= (str &x) //overloading >= operator
        {
         if(strlen(s)>=strlen(x.s))
         { return 1;} 

         return 0;
        }
};

int main()
{
 str s1,s2,s3,s4,s5;

 cout<<endl<<"---Adding two string objects---"<<endl;
 cout<<"\nEnter string 1: ";
 s1.input();
 cout<<"Enter string 2: ";
 s2.input();
 cout<<"\nString 1 is : ";
 s1.display();
 cout<<"String 2 is : ";
 s2.display();

 s3=s1+s2; //concatenation
 cout<<"\nNew string is : ";
 s3.display();

 cout<<endl<<"---Comparing two strings---"<<endl;
 cout<<"Enter string 4 : ";
 s4.input();
 cout << "Enter string 5 :";
 s5.input();
 cout << "\nString 4 is : ";
 s4.display();
 cout << "String 5 is : ";
 s5.display();
 if (s4 >= s5)
{
 cout << "\nThe largest string is : ";
 s4.display();
}
else 
{
 cout << "\nThe largest string is :";
 s5.display();
}
 
return 0;
}