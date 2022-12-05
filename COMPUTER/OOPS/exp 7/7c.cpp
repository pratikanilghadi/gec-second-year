#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
 double term=0, sum=0;
 cout.setf(ios::showpoint);
 cout<<setw(2)<<"n"<<setw(15)<<"Inverse_of_n"<<setw(15)<<"Square_of_n"<<endl;

 for(int i=1;i<=10;i++)
 {
  term=1.0/float(i);
  sum=sum+term;
  cout<<setw(2)<<i<<setw(14)<<setprecision(4)<<setiosflags(ios::scientific)<<term<<setw(13)<<resetiosflags(ios::scientific)<<sum<<endl;
 }
 return 0;
}
