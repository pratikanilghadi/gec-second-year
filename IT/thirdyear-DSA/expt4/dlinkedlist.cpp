#include <iostream>

using namespace std;

// Node Defination
//--------------------------Node Defination---------------------
template<class VAR>
class node
{
    public:
    VAR value;
    node *next;
    node *prev;

    node(VAR data)
    {
        value = data;
        next = NULL;
        prev = NULL;
    }
};

//---------------------------LinkedList Defination--------------
template<class TYPE>
class dlinkedlist
{
    node<TYPE> *head;
    int count;

    public:
    dlinkedlist()
    {
        head = NULL;
        count = 0;
    }

    void insert();
    void create();
    void remove();
    void display();
    void search();
    void sort();
    dlinkedlist<TYPE> split();
    void merge(dlinkedlist<TYPE> list2);
};

//---------------------------Split Function---------------------
template<class TYPE>
dlinkedlist<TYPE> dlinkedlist<TYPE>:: split()
{
    dlinkedlist<TYPE> list2;
    node<TYPE> *temp= head;
    for (int i = 0; i < count/2; i++)
    {
        temp = temp->next;
    }
    list2.head = temp->next;
    temp->next->prev = NULL;
    temp->next = NULL;
    return list2;
}

//---------------------------Merge Function---------------------
template<class TYPE>
void dlinkedlist<TYPE>:: merge(dlinkedlist<TYPE> list2)
{
    node<TYPE> *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = list2.head;
    list2.head->prev = temp;
}

//---------------------------Search Function--------------------
template<class TYPE>
void dlinkedlist<TYPE>:: search()
{
    TYPE value;
    cout << "Enter the value to be searched: ";
    cin >> value;
    node<TYPE> *temp = head;
    int pos = 0;
    while(temp != NULL)
    {
        if(temp->value == value)
        {
            cout << "Value found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found" << endl;
}

//---------------------------Sort Function----------------------
template<class TYPE>
void dlinkedlist<TYPE>:: sort()
{
    node<TYPE> *temp = head;
    int buffer;
    for (; temp->next != NULL; temp = temp->next)
    {
        node<TYPE> *temp2 = temp;
        for (; temp2->next != NULL; temp2 = temp2->next)
        {
            if(temp2->value > temp2->next->value)
            {
                buffer = temp2->value;
                temp2->value = temp2->next->value;
                temp2->next->value = buffer;
            }
        }
    }
}

//----------------------------Insert Funciton--------------------
template <class TYPE>
void dlinkedlist<TYPE>:: insert()
{
    int pos;
    cout << "Enter the position where the element is to be inserted" << endl;
    cin >> pos;
    if (pos > count+1)
    {
        cout << "The position doesn't exists" << endl;
        return;
    }

    TYPE data;
    cout << "Enter the data to be inserted: ";
    cin >> data;
    node<TYPE> *p = new node<TYPE>(data);

    if (pos == 1)
    {
        if (head == NULL)
        {
            head = p;
            count++;
            return;
        }
        node<TYPE> *temp = head;
        head->next->prev = p;
        p->next = head->next->prev;
        head = p;
        count++;
    }

    else
    {
        node<TYPE> *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        
        p->next = temp->next;
        p->prev = temp;
        temp->next->prev = p;
        temp->next = p;
    }

}

//----------------------------Create Funciton--------------------
template <class TYPE>
void dlinkedlist<TYPE>:: create()
{
    TYPE data;
    cout << "Enter the value to be inserted" << endl;
    cin >> data;

    node<TYPE> *p = new node<TYPE>(data);
    if (head == NULL)
    {
        head = p;
        count++;
    }

    else
    {
        node<TYPE> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
        p->prev = temp;
        count++;
    }
}

//----------------------------Remove Funciton--------------------
template <class TYPE>
void dlinkedlist<TYPE>:: remove()
{
    int pos;
    cout << "Enter the index of element to be removed" << endl;
    cin >> pos;

    if (pos > count)
    {
        cout << "The Positon doesn't exists" << endl;
    }

    else if (pos == 1)
    {
        node<TYPE> *temp = head;
        head = head->next;
        head->prev = NULL;
        delete(temp);
        count--;
    }

    else
    {
        node<TYPE> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(temp);
        count--;
    }
}

//----------------------------Display Funciton-------------------
template <class TYPE>
void dlinkedlist<TYPE>:: display()
{
    node<TYPE> *temp = head;
    if (head == NULL)
    {
        return;
    }

    cout << "[ ";
    while(temp != NULL)
    {
        cout << temp->value << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

//----------------------------Main Defination---------------------
//----------------------------Class Object: obj------------------
int main()
{
    dlinkedlist<char> obj;
    dlinkedlist<char> obj2;
    int choice;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Create" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Display" << endl;
        cout << "5. Search" << endl;
        cout << "6. Sort" << endl;
        cout << "7. Split" << endl;
        cout << "8. Merge" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.create();
                break;
            case 3:
                obj.remove();
                break;
            case 4:
                obj.display();
                break;
            case 5:
                obj.search();
                break;
            case 6:
                obj.sort();
                break;
            case 7:
                obj2 = obj.split();
                break;
            case 8:
                obj.merge(obj2);
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}