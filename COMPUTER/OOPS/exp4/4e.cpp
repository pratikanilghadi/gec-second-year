#include<iostream>

using namespace std;

int i;

class Vector
{
 private:
         int *a;
         int n;
 public:
        Vector(int p)
        {
         a = new int[p]; //dynamic allocation
         n = p;
        }

        void input()
        {
         cout << "Enter the elements: " << endl;
         for(i=0;i<n;i++)
         {
          cin >> a[i];
         }
        }

        void display()
        {
         cout << "[" ;
         for(i=0;i<n;i++)
         {
          if (i == n-1)
          {
           cout << a[i]; 
          }
          else
          {
           cout << a[i] << " ";
          } 
         }
         cout << "]" << endl;
        }
       
        Vector operator + (Vector y)
        {
         Vector V(n);
         
         for(int i=0;i<n;i++)
         {
          V.a[i] = a[i] + y.a[i];
         }
         return V;
        }

        Vector operator * (int y)
        {
         Vector X(n);
         
         for(int i=0;i<n;i++)
         {
          X.a[i] = a[i]*y;
         }
         return X;
        }
};
int main()
{
 int m,n1;
 cout << "\nEnter the number of elements you wish to enter: ";
 cin >> n1;

 Vector v1(n1),v2(n1),v3(n1);
 v1.input();
 v2.input();
	
 cout << "\nVector 1 is: ";
 v1.display();
    
 cout << "Vector 2 is: ";
 v2.display();
		
 cout << "\nEnter a scalar value:";
 cin >> m;
	
 v2 = v2*m;
 cout << "v2 on multiplying by " << m << " is: ";
 v2.display();
	
 v3 = v1 + v2;
 cout << "\nThe vector obtained upon adding v1 and v2 is: ";
 v3.display();
 return 0;
}
