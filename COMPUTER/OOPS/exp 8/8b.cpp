#include<iostream>

using namespace std;

template<class T>
class vector
{
 T *v;
 int size;

 public:vector(int p)
        {
         v=new T[p];
         size=p;
        }
        void create();
        void modify();
        void display();
};

template<class T>
void vector<T>::create()
{
 cout<<"Enter the elemnts of the vector"<<endl;
 for(int i=0;i<size;i++)
 { cin>>v[i];}
}

template<class T>
void vector<T>::modify()
{
        int i;
 cout<<"Enter the position to be modified"<<endl;
 cin>>i;
 if(i<size)
 {
        cout<<"Enter the new value"<<endl;
        cin>>v[i];
 }
 else
 { cout<<"Invalid position"<<endl;}
 
}

template<class T>
void vector<T>::display()
{
 cout<<"[";
 for(int i=0;i<size;i++)
 {
  if(i==size-1)
  { cout<<v[i];}
  else
  { cout<<v[i]<<" "; }
 }
 cout<<"]"<<endl;
}

int main()
{
        int n,op;
        cout<<"Enter the size of the vector"<<endl;
        cin>>n;
        vector <int> v(n);
        while(1)
        {
                cout<<"\n--------------------------\n";
                cout<<"1.Create"<<endl;
                cout<<"2.Modify"<<endl;
                cout<<"3.Display"<<endl;
                cout<<"4.Exit"<<endl;
                cin>>op;

                switch(op)
                {
                        case 1:v.create();
                               break;

                        case 2:cout<<"Vector Before Modification is : ";
                               v.display();
                               v.modify();
                               cout<<"Vector After Modification is : ";
                               v.display();
                               break;

                        case 3:v.display();
                               break;

                        case 4:exit(0);

                        default:cout<<"Invalid Option"<<endl;
                }
        }    
return 0;
}