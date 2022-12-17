/*1 Write a program that reads a text file and creates another file that is identical except 
that every sequence of consecutive blank spaces is replaced by a single space*/
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

int main()
{
 string s;
 cout<<"Enter the Paragraph: ";
 getline(cin,s);
 ofstream fout("infile.txt",ios :: out);
 for(int i=0;i<s.length();i++)
 {
  fout.put(s[i]);
 }
 fout.close();

 ifstream fin("infile.txt",ios :: in);
 cout<<"\nThe contents of the file are: \n";
 while(fin)
 {
  char ch;
  fin.get(ch);
  cout<<ch;
 }
 fin.close();

 fout.open("Outfile.txt");
 fin.open("infile.txt");
 cout<<"\nContents of the file after copying are: \n";
 while(fin.eof()==0)
 {
  char ch;
  fin.get(ch);
  if(ch==' ')
  {
   char next;
   fout.put(ch);
   while(ch==' ')
   {
    ch=fin.get();
    next=ch;
   }
   fout.put(next);
  }
   else
   {
    fout.put(ch);
   }
 }
 fin.close();
 fout.close();
 fin.open("Outfile.txt");
 while(fin.eof()==0)
 {
  char ch;
  fin.get(ch);
  cout<<ch;
 }
return 0;
}