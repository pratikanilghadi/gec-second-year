#include<iostream>

using namespace std;

string * bsort(string *names,int len)
{
    for ( int i = 0; i < len; i++)
    {
        for ( int j = 0; j < len - i -1; j++)
        {
            if (names[j] < names[j+1])
            {
                string temp = names[j+1];
                names[j+1] = names[j];
                names[j] = temp;
            }
        }
    }
    return names;
}

int main(void)
{
    cout << "How many names do you want to Enter" ;
    int num;
    cin >> num;

    cout << endl;
    cout << "Enter " << num << " names" << endl;
    string *names = new string[num];

    for (int i = 0; i < num; i++)
    {
        cin >> names[i];
    }

    names = bsort(names,num);

    for ( int i = 0; i < num; i++)
    {
        cout << names[i] << endl;
    }
}