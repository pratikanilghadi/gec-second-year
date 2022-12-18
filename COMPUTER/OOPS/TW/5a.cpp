/*Using standard library string class , implement a program to check whether the given string is palindrome or not*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
 string str;
 cout<<"Enter a string: ";
 cin>>str;
 int len=str.length();
 int flag=0;
 for(int i=0;i<len/2;i++)
 {
  if(str[i]!=str[len-i-1])
  {
   flag=1;
   break;
  }
 }
 if(flag==1)
 {
  cout<<"String is not a palindrome";
 }
 else
 {
  cout<<"String is a palindrome";
 }
 return 0;
}