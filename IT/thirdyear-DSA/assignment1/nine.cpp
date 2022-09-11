#include<iostream>

using namespace std;

class bank
{
    private:
    string name;
    int account;
    char type;
    float amount;

    public:
    bank(string person,int number,char typing,float cash)
    {
        name = person;
        account = number;
        type = typing;
        amount = cash;
    }

    void deposit()
    {
        float sum;
        cout << "Enter the money to be deposited : ";
        cin >> sum;
        cout << endl; 
        amount += sum;
        cout << "Updated amount is : " << amount << endl << endl;
    }

    void withdraw()
    {
        cout << "Current Balance is : " << amount << endl;
        cout << "Enter the amount to withdrawn : ";

        float money;
        cin >> money; 
        amount -= money;

        cout << "Updated Balance is : " << amount << endl;
    }

    void display()
    {
        cout << "Name : " << name << endl << "Balance : " << amount << endl;
    }
};

int main(void)
{
  string name;
  int number;
  char type;
  float amount;

  cout << "Enter the Name of the account holder : " ;
  cin >> name;
  cout << endl << "Enter the account number : ";
  cin >> number;
  cout << endl << "Enter the type of account \nA)SAVINGS account \nB)CURRENT acount" <<endl;
  cin >> type;
  cout << endl << "Enter the amount to deposited : ";
  cin >> amount;
  cout << endl;

  bank person(name,number,type,amount);
  person.deposit();
  person.withdraw();
  person.display();

  return 0;


}