#include<iostream>

using namespace std;

int main(void)
{
    cout << "Enter the number of layer you want" << endl;
    int layers;
    cin >> layers;
    int counter = 1;

    for (int i = 0; i < layers; ++i)
    {
        for (int j = 0; j < i + 1; j++)
            cout << counter++ << " ";
        cout << endl;
    }
}