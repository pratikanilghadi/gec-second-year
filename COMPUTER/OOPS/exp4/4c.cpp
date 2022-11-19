#include<iostream>

using namespace std;

class area
{
 private:
         float height;
         float base;
         float ans;

 public:
        friend istream & operator >> (istream &,area &);
        friend ostream & operator << (ostream &,area &);
};

istream & operator >> (istream &din,area &b) //extraction operator overloading
{
 cout<<"Enter height of the Triangle: ";
 din>>b.height;
 cout<<"Enter base of the Triangle: ";
 din>>b.base;
 return(din);
}

ostream & operator << (ostream &dout,area &b) //insertion operator overloading
{
 dout<<endl;
 dout<<"Height of triangle: "<<b.height<<endl;
 dout<<"Base of triangle: "<<b.base<<endl;
 b.ans=0.5*b.base*b.height;
 dout<<"Area of the triangle: "<<b.ans<<endl;
 return(dout);
}

int main()
{
 area a;
 cin>>a;
 cout<<a;
 return 0;
}