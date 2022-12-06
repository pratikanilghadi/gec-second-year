#include<iostream>

using namespace std;

class merge
{
    int a[100],n,m;
    public:
    void getdata();
    void sort(int arr[],int min,int max);
    void display();
    void join(int arr[],int min,int mid,int max);
};

void merge::getdata()
{
    cout << "Enter the size of the array:";
    cin >> n;
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,0,n);
}

void merge:: join(int arr[],int min,int mid,int max)
{
    for (int i = min; i < mid; i++)
    {
        for (int j = mid; j < max; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge::sort(int arr[],int min,int max)
{
    int mid;
    if (min < max)
    {
        mid = (min + max) / 2;
        sort(arr,min,mid);
        sort(arr,mid+1,max);
        join(arr,min,mid,max);
    }
}

void merge::display()
{
    cout << "The sorted array is:";
    for (int var = 0; var < n; var++)
    {
        cout << a[var] << " ";
    }
}


int main()
{
    merge obj;
    obj.getdata();
    obj.display();
    return 0;
}