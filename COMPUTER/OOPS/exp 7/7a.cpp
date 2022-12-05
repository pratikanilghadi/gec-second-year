#include<iostream>
#include<string.h>

using namespace std;

int main()
{
 char *s= "object";
 int l=strlen(s);
 for(int i=0;i<l;i++)
 {
  for(int j=0;j<l-i;j++)
  {
   cout<<s[j];
  }
  cout.width(2*i+2);
  
  for(int j=l-1-i;j>=0;j--)
  {
   if(i==5)
  {
   cout.fill('*');
  }
   cout<<s[j];
   cout.fill(' ');
  }
  printf("\n");
 }

 for(int i=l-1;i>0;i--)
 {
  cout.width(0);
  for(int j=0;j<l-i+1;j++)
  {
   cout<<s[j];
  }
  cout.width(2*i);
  for(int j=l-i;j>=0;j--)
  {
   cout<<s[j];
  }
  cout<<endl;
 }
return 0;
}