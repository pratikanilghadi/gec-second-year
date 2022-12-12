#include <iostream>

using namespace std;

//! Node Defination
template <class VAR>
class node
{
    public:
    VAR data;
    node *next;
    node(VAR value)
    {
        data = value;
        next = NULL;
    }
    node()
    {
        next = NULL;
    }
};

//! Linked List Class Defination
template <class TYPE>
class linkedlist
{  
    node<TYPE> *head;
    int count;

    public:
    linkedlist() { head = NULL; count = 0; }
    void create();
    void display();
    void insert();
    void remove();
    void search();
    void sort();
    linkedlist<TYPE> split();
    void merge(linkedlist<TYPE> list2);
};

//! The merge Function : takes a linked list as argument and merges it with the current list
template <class TYPE>
void linkedlist<TYPE>:: merge(linkedlist<TYPE> list2)
{
    node<TYPE> *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = list2.head;
}

//! The split Function : splits the list into two halves and returns the second half
template <class TYPE>
linkedlist<TYPE> linkedlist<TYPE>:: split()
{
    linkedlist<TYPE> list2;
    node<TYPE> *temp= head;
    for (int i = 0; i < count/2; i++)
    {
        temp = temp->next;
    }
    list2.head = temp->next;
    temp->next = NULL;
    return list2;
}

//! The sort Function : sorts the list in ascending order
template <class TYPE>
void linkedlist<TYPE>:: sort()
{
    node<TYPE> *temp = head;
    int buffer;
    for (; temp->next != NULL; temp = temp->next)
    {
        node<TYPE> *temp2 = temp;
        for (; temp2->next != NULL; temp2 = temp2->next)
        {
            if(temp2->data > temp2->next->data)
            {
                buffer = temp2->data;
                temp2->data = temp2->next->data;
                temp2->next->data = buffer;
            }
        }
    }
}

//! The search Function : searches for a given value in the list
template <class TYPE>
void linkedlist<TYPE>:: create()
{
    TYPE value;
    cout << "Enter the value of the node: " << endl;
    cin >> value;
    node<TYPE> *p = new node<TYPE>(value);
    if(head == NULL)
    {
        head = p;
        count++;
    }
    else
    {
        node<TYPE> *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        count++;
    }
}

//! The display Function : displays the list
template <class TYPE>
void linkedlist<TYPE>:: display()
{
    node<TYPE> *temp = head;
    if (head == NULL)
    {
        return;
    }

    cout << "[ ";
    while(temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

//! The insert Function : inserts a node at a given position
template <class TYPE>
void linkedlist<TYPE>:: remove()
{
    int position;
    cout << "Enter the position of the node to be deleted: " << endl;
    cin >> position;
    if(position > count)
    {
        cout << "Invalid position" << endl;
    }

    else
    {
        node<TYPE> *temp = head;
        if(position == 1)
        {
            head = temp->next;
            delete temp;
            count--;
        }
        else
        {
            for(int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            node<TYPE> *p = temp->next;
            temp->next = p->next;
            delete p;
            count--;
        }
    }
}

//! The insert Function : inserts a node at a given position
template <class TYPE>
void linkedlist<TYPE>:: insert()
{
    TYPE value;
    cout << "Enter the value of the node: " << endl;
    cin >> value;
    node<TYPE> *p = new node<TYPE>(value);
    int position;
    cout << "Enter the position of the node to be inserted: " << endl;
    cin >> position;
    if(position > count+1)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        if(position == 1)
        {
            p->next = head;
            head = p;
            count++;
        }
        else
        {
            node<TYPE> *temp = head;
            for(int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
            count++;
        }
    }
}

// The search Function : searches for a given value in the list
template <class TYPE>
void linkedlist<TYPE>:: search()
{
    int value;
    cout << "Enter the value of the node to be searched: " << endl;
    cin >> value;
    int index;
    bool flag = false;
    node<TYPE> *temp = head;
    for (int i = 0; temp != NULL; temp = temp->next, i++)
    {
        if(temp->data == value)
        {
            flag = true;
            index = i;
            break;
        }
    }
    if(flag)
    {
        cout << "The value is present at position " << index + 1 << endl;
    }
    else
    {
        cout << "The value is not present in the list" << endl;
    } 
}

// Main Function - Creates a linked list and performs various operations on it
int main(void)
{
    linkedlist<char> list;
    linkedlist<char> list2;
    int choice;
    do
    {
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Remove" << endl;
        cout << "5. Search" << endl;
        cout << "6. Sort" << endl;
        cout << "7. Split" << endl;
        cout << "8. Merge" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                list.create();
                break;
            case 2:
                list.display();
                break;
            case 3:
                list.insert();
                break;
            case 4:
                list.remove();
                break;
            case 5:
                list.search();
                break;
            case 6:
                list.sort();
                break;
            case 7:
                list2 = list.split();
                break;
            case 8:
                list.merge(list2);
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }while(choice != 9);
    return 0;
}