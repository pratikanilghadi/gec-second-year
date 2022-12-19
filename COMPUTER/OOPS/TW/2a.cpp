/*Design and implement a class  string using an array of size 20 .The class should contain the nescessary constructor , destructor ,overloaded assignment operator and a friend function for concatinate two strings*/
#include<iostream>
#include<string.h>

using namespace std;

class str
{
 char s[20];
 int len;

 public:str(){}
        str(const char *s1)
        {
         len=strlen(s1);
         strcpy(s,s1);
        }

        void operator=(str s1);

        void display()
        {
         cout<<s<<endl;
        }

        ~str()
        {
         s[20]={};
        }

        friend str operator+(str &s1,str &s2);
};

str operator+ (str &s1,str &s2)
{
 char temp[s1.len+s2.len+1];
 strcpy(temp,s1.s);
 strcat(temp,s2.s);
 return temp;
}

void str :: operator=(str s1)
{
 strcpy(s,s1.s);
}

int main()
{
 str s1("Hello");
 str s2("World");
 str s3;
 s3 = s1+s2;
 cout<<"String 1: ";
 s1.display();
 cout<<"String 2: ";
 s2.display();
 cout<<"String 3: ";
 s3.display();
 return 0;
}