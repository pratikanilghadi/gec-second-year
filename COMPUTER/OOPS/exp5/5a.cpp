#include<iostream>
#include<cstring>

using namespace std;

class student
{
 protected:
           char name[20];
           int roll_no;
           char college[20];
           int uni_reg_no;

 public:
        void getdata()
        {
         fflush(stdin);     
         cout<<"Enter name: ";
         cin>>name;
         cout<<"Enter roll no: ";
         cin>>roll_no;
         fflush(stdin);
         cout<<"Enter college: ";
         cin>>college;
         cout<<"Enter university registration no: ";
         cin>>uni_reg_no;
        }

        void display()
        {
         cout<<"Name: "<<name<<endl;
         cout<<"Roll no: "<<roll_no<<endl;
         cout<<"College: "<<college<<endl;
         cout<<"University registration no: "<<uni_reg_no<<endl;
        }
};

class arts:public student
{
 string arts_sub;

 public:
        arts()
        {
         arts_sub="Fine Arts";
        }

        void arts_display()
        {
         this->display();
         cout<<"Subject: "<<arts_sub<<endl;
        }
};

class medical:public student
{
 string med_sub;

 public:
        medical()
        {
         med_sub="Autonomy";
        }

        void medical_display()
        {
         this->display();
         cout<<"Subject: "<<med_sub<<endl;
        }
};

class engineering:public student
{
 protected:
           string branch;
           string common_sub1;
           string common_sub2;

 public:
        engineering()
        {
         common_sub1="Mathematics";
         common_sub2="Physics";
        }
};

class mech:public engineering
{
 string mech_sub;

 public:
        mech()
        {
         branch="Mechanical" ;	
         mech_sub="Mechanical Drawing";
        }

        void mech_display()
        {
         this->display();
         cout<<"common subject 1: "<<common_sub1<<endl;
         cout<<"common subject 2: "<<common_sub2<<endl;
         cout<<"Branch: "<<branch<<endl;
         cout<<"Subject: "<<mech_sub<<endl;
        }
};

class elec:public engineering
{
 string elec_sub;

 public:
        elec()
        {
         branch="Electrical and Electronics";	
         elec_sub="Circuit Analysis";
        }

        void elec_display()
        {
         this->display();
         cout<<"common subject 1: "<<common_sub1<<endl;
         cout<<"common subject 2: "<<common_sub2<<endl;
         cout<<"Branch: "<<branch<<endl;
         cout<<"Subject: "<<elec_sub<<endl;
        }
};

class civil:public engineering
{
 string civil_sub;

 public:
        civil()
        {
         branch="Civil";	
         civil_sub="Building Construction";
        }

        void civil_display()
        {
         this->display();
         cout<<"common subject 1: "<<common_sub1<<endl;
         cout<<"common subject 2: "<<common_sub2<<endl;
         cout<<"Branch: "<<branch<<endl;
         cout<<"Subject: "<<civil_sub<<endl;
        }
};

int main()
{
 int op=0,na=0,nm=0,nmech=0,nelec=0,ncivil=0;
 char branch_code;
 mech *m;
 elec *e;
 civil *c;

 while(1)
 {
  cout<<"\n-----------------------------\n";
  cout<<"1-Enter details of arts students"<<endl;
  cout<<"2-Enter details of medical students"<<endl;
  cout<<"3-Enter details of engineering students"<<endl;
  cout<<"4-Display details of arts students"<<endl;
  cout<<"5-Display details of medical students"<<endl;
  cout<<"6-Display details of engineering students"<<endl;
  cout<<"7-Exit"<<endl;
  cout<<"Enter your choice: ";
  cin>>op;

  switch(op)
  {
   case 1:cout<<"Enter the number of arts students: ";
          cin>>na;
          arts *a;
          a = new arts[na];
          for(int i=0;i<na;i++)
          {
           cout<<"\nEnter details of student "<<i+1<<endl;
           a[i].getdata();
           if(i!=na-1)
           {
            cout<<"-----------------------------\n";
           }
          }
          break;

   case 2:cout<<"Enter the number of medical students:";
   cin>>nm;

   medical *med;
   med = new medical[nm];
   cout<<"\n--------------------------------\n";
   for(int i=0;i<nm;i++)
   {
    med[i].getdata();
    if(i!=nm-1)
    {
     cout<<"--------------------------------\n";
    }
   }
   break;

   case 3:cout<<"a.Mechanical"<<endl;
          cout<<"b.Electrical"<<endl;
          cout<<"c.Civil"<<endl;
          cout<<"Enter the branch code: ";
          fflush(stdin);
          cin>>branch_code;

          switch(branch_code)
          {
           case 'a':cout<<"Enter the number of mechanical students:";
                    cin>>nmech;
                    m = new mech[nmech];
                    cout<<"\n--------------------------------\n";
                    for(int i=0;i<nmech;i++)
                    {
                     m[i].getdata();
                     if(i!=nmech-1)
                     {
                      cout<<"--------------------------------\n";
                     }
                    }
                    break;
           
           case 'b':cout<<"Enter the number of electrical students:";
                    cin>>nelec;
                    e = new elec[nelec];
                    cout<<"\n--------------------------------\n";
                    for(int i=0;i<nelec;i++)
                    {
                     e[i].getdata();
                     if(i!=nelec-1)
                     {
                      cout<<"--------------------------------\n";
                     }
                    }
                    break;

           case 'c':cout<<"Enter the number of civil students:";
                    cin>>ncivil;
                    c = new civil[ncivil];
                    cout<<"\n--------------------------------\n";
                    for(int i=0;i<ncivil;i++)
                    {
                     c[i].getdata();
                     if(i!=ncivil-1)
                     {
                      cout<<"--------------------------------\n";
                     }
                    }
                    break;

             default:cout<<"Invalid Branch code"<<endl;
          }//end of branch switch
          break;

   case 4:if(na==0)
          {
           cout<<"No entries found"<<endl;
           break;
          }
          cout<<"\nDetails of arts students:"<<endl; 
          for(int i=0;i<na;i++)
          {
           a[i].arts_display();
           if(i!=na-1)
           {
            cout<<"-----------------------------\n";
           }
          }
          break;

  case 5:if(nm==0)
         {
          cout<<"No entries found"<<endl;
          break;
         }
         else
         {
         	cout<<"\nDetails of medical students:"<<endl;
         for(int i=0;i<nm;i++)
         {
          med[i].medical_display();
          if(i!=nm-1)
          {
           cout<<"-----------------------------\n";
          }
         }
         
		 }
         break;

 case 6:cout<<"\nChoose from the branch given below"<<endl;
        cout<<"a.Mechanical"<<endl;
        cout<<"b.Electrical"<<endl;
        cout<<"c.Civil"<<endl;
        cout<<"Enter the branch code: ";
        fflush(stdin);
        cin>>branch_code;

        switch(branch_code)
        {
         case 'a':if(nmech==0)
                  {
                   cout<<"No entries found"<<endl;
                   break;
                  }
                  cout<<"\nDetails of mechanical students:"<<endl;
                  for(int i=0;i<nmech;i++)
                  {
                   m[i].mech_display();
                   if(i!=nmech-1)
                   {
                    cout<<"-----------------------------\n";
                   }
                  }
                  break;

         case 'b':if(nelec==0)
                  {
                   cout<<"No entries found"<<endl;
                   break;
                  }
                  cout<<"\nDetails of electrical students:"<<endl;
                  for(int i=0;i<nelec;i++)
                  {
                   e[i].elec_display();
                   if(i!=nelec-1)
                   {
                    cout<<"-----------------------------\n";
                   }
                  }
                  break;

         case 'c':if(ncivil==0)
                  {
                   cout<<"No entries found"<<endl;
                   break;
                  }
                  cout<<"\nDetails of civil students:"<<endl;
                  for(int i=0;i<ncivil;i++)
                  {
                   c[i].civil_display();
                   if(i!=ncivil-1)
                   {
                    cout<<"-----------------------------\n";
                   }
                  }
                  break;
                 
  case 7:exit(1);

         default:cout<<"Invalid Branch code"<<endl;
        }//end of branch switch
        break;



  }//end of main switch

 }//end of while loop
}
