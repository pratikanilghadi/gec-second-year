#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
 char para[100],c;
 int line=0,word=0,character=0,space=0;
 cout<<"Enter a paragraph: ";
 cout << "Enter ^ if u want to finish the paragraph" << endl;
 cin.get(c);
int i=0;
 while(c!='^')
 {
  if(c=='^')
  {
   break;
  }
  para[i]=c;
  i++;
  cin.get(c);
 }

 cout<<"The paragraph is: "<<para<<endl;
 for(int i=0;para[i]!='\0';i++)
 {
  character++;
  if(para[i]==' ')
  {
   word++;
   space++;
  }
  if(para[i]=='\n')
  {
   line++;
  }
 }
 character=abs(word-character);
 word=word+line;
 character=character-1;

 cout << setw(20) << "COLUMN 1" << setw(20) << "COLUMN 2" << endl;
	
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(20) << "Number of lines" << setw(20);
	cout.setf(ios::right, ios::adjustfield);
	cout << line << endl;
	
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(20) << "Number of words" << setw(20);
	cout.setf(ios::right, ios::adjustfield);
	cout << word << endl;
	
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(20) << "Number of characters" << setw(20);
	cout.setf(ios::right, ios::adjustfield);
	cout << character << endl;
	
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(20) << "Number of spaces" << setw(20);
	cout.setf(ios::right, ios::adjustfield);
	cout << space << endl;
	return 0;
}