/*Define two classes Polar(r,a) and Rectangle (x,y) to represent points the polar and rectangle systes . Use conversion routine to convert from one system to the other .*/

#include<iostream>
#include<math.h>

using namespace std;
class rectangle;

class Polar
{
       float r;
       float a;

       public:
       Polar(){}
       Polar(float a1,float r1)
       {
              r=r1;
              a=a1;
       }

       Polar(rectangle temp);
       void get_Polar()
       {
              cout<<"Enter a: ";
              cin>>a;
              cout<<"Enter r: ";
              cin>>r; 
       }
       void Display_Polar()
       {
              cout<<"Polar cordinates : \n";
              cout<<"a: "<<a<<endl;
              cout<<"r: "<<r<<endl;
       }
       int get_r()
       {
              return r;
       }
       int get_a()
       {
              return a;
       }
       friend class Rectangle;
};

class rectangle
{
       float x;
       float y;

       public:
              rectangle(){}
              rectangle(int z,int v)
              {
                     x=z;
                     y=v;
              }
              rectangle(class Polar p);
              void get_Rectangle()
              {
                     cout<<"Enter x: ";
                     cin>>x;
                     cout<<"Enter y: ";
                     cin>>y;
              }
              void Display_Rectangle()
              {
                     cout<<"Rectangle cordinates : \n";
                     cout<<"x: "<<x<<endl;
                     cout<<"y: "<<y<<endl;
              }
              friend class Polar;
};

rectangle::rectangle(class Polar p)
{
       x=p.get_r()*cos(p.get_a());
       y=p.get_r()*sin(p.get_a());
}

Polar :: Polar(rectangle temp)
{
       a=atan(temp.x/temp.y);
       r=sqrt(temp.x*temp.x+temp.y*temp.y);
}


int main()
{
       int op;
       Polar p1;
       rectangle r1;
       
       while(1)
       {
        cout<<"1. Polar to Rectangle\n";
        cout<<"2. Rectangle to Polar\n";
              cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>op;      
       switch(op)
       {
        case 1:p1.get_Polar();
               p1.Display_Polar();
               r1=p1;
               r1.Display_Rectangle();
               break;
                     
       case 2:r1.get_Rectangle();
              r1.Display_Rectangle();
              p1=r1;
              p1.Display_Polar();
              break;
       
       case 3:exit(0);

       default:cout<<"Invalid choice\n";

                        
       }
       }
}
