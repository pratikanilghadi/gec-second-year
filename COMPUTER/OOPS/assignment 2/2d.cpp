#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
 int cons[5],vote,spoilt=0,total=0;
 char ch;
 for(int i=0;i<5;i++)
 {
  cons[i]=0;
 }
 do
 {
   cout<<"To cast your vote enter a number between 1 to 5"<<endl;
   cin>>vote;
   switch(vote)
   {
     case 1:cons[0]=cons[0]+1;
     	     total++;
            break;
     case 2:cons[1]=cons[1]+1;
            total++;
	     break;
     case 3:cons[2]=cons[2]+1;
            total++;
	     break;
     case 4:cons[3]=cons[3]+1;
            total++;
            break;
     case 5:cons[4]=cons[4]+1;
            total++;
	     break;
     default:spoilt++;
     	      total++;
  }
  cout<<"Do you want too continue? (y for yes) ";
  cin>>ch;
 }while(ch=='y');

cout<<endl<<setw(17)<<"--Results--"<<endl<<endl;
cout<<setw(7)<<"Name "<<setw(25)<<" Number of votes"<<endl;
for(int i=0;i<5;i++)
{
  cout<<"contestant "<<i+1<<setw(13)<<cons[i]<<endl;
}
cout<<"Total number of spoilt ballots are: "<<spoilt<<endl;
cout<<"Total number of Votes casted are :"<<total<<endl;
return 0;
}