#include<iostream>

using namespace std;

class alpha
{
 private:
         int x;

 public:
        alpha(int i)
        {
         x=i;
         cout<<"Alpha initialised x\n";
        }
        void display_x()
        {
         cout<<"x = "<<x<<endl;
        }
};

class beta
{
 private:
         float y;

 public:
        beta(float j)
        {
         y=j;
         cout<<"\nBeta initialised y\n";
        }
        void display_y()
        {
         cout<<"y = "<<y<<endl;
        }
};

class gama:public beta,public alpha
{
 int m,n;

 public:
        gama(int a,float b,int c,int d):alpha(a),beta(b)
        {
         m=c;
         n=d;
         cout<<"Gamma initialised m, n\n";
        }
        void display_mn()
        {
         cout<<"m = "<<m<<endl;
         cout<<"n = "<<n<<endl;
        }
};

int main()
{
 int a,c,d;
 float b;
 cout<<"Enter the data of a, b, c, d: ";
 cin>>a>>b>>c>>d;
 gama g(a,b,c,d);
 cout<<endl;
 g.display_x();
 g.display_y();
 g.display_mn();
 return 0;
}