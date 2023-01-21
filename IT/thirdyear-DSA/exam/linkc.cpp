#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }
};

//! THE LINKEDLIST CLASS---------------------------------------------------------
class linkedlist
{
    private:
    node *head;

    public:
    linkedlist()
    {
        head = NULL;
    }
    void start();
    void insertfirst();
    void insertlast();
    void insertmiddle();
    void display();
    void reversedisplay(node *temp);
    void remove();
};

void linkedlist :: start()
{
    int ch = 0;
    do
    {
        cout << "Enter your choice" << endl;
        cout << "1.First" << endl << "2.Second" << endl << "3.Middle" << endl << "4.Display" << endl << "5.Reverse" << endl << "6.Remove" << endl << "7.Exit" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
            insertfirst();
            break;

            case 2:
            insertlast();
            break;

            case 3:
            insertmiddle();
            break;

            case 4:
            display();
            break;

            case 5:
            if (head  == NULL)
            cout << "List is empty" << endl;
            else
            reversedisplay(head);
            break;

            case 6:
            remove();
            break;
        }
    } while (ch != 7);
}


//! Insertfirst ------------------------------------------------------------------------
void linkedlist:: insertfirst()
{
    node *p = new node();
    cout << "Enter a value to be inserted" << endl;

    int value;
    cin >> value;
    p->data = value;

    if (head == NULL)
    {
        head = p;
        return;
    }

    p->next = head;
    head = p;
}

//! Insertlast ------------------------------------------------------------------------------
void linkedlist:: insertlast()
{
    node *p = new node();
    cout << "Enter a value to be inserted" << endl;

    int value;
    cin >> value;
    p->data = value;

    if (head == NULL)
    {
        head = p;
        return;
    }

    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;
}

//! Insertmiddle -------------------------------------------------------------------------------
void linkedlist:: insertmiddle()
{
    node *p = new node();
    cout << "Enter a value to be inserted" << endl;

    int value;
    cin >> value;
    p->data = value;

    cout << "Enter the location to be inserted" << endl;
    int pos;
    cin >> pos;

    //? Start
    if (pos == 1)
    {
        p->next = head;
        head = p;
        return;
    } 

    int count = 1;
    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        count++; 
    }

    //? Last
    if(pos == count + 1)
    {
        temp->next = p;
        return;
    }

    node *temp2 = head;
    for(int i = 1;i < pos - 1; i++)
    {
        temp2 = temp2->next;
    }
    p->next = temp2->next;
    temp2->next = p;
}

//! Display
void linkedlist:: display()
{
    node *temp = head;
    if (temp == NULL)
    {
        cout << "The linkedlist is empty" << endl;
        return;
    }
    cout << temp->data << endl;

    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << endl;
    }
}

//! reverse
void linkedlist:: reversedisplay(node *temp)
{
    if(temp->next != NULL)
    {
        reversedisplay(temp->next);
    }
    cout << temp->data << endl;
    return;
}

//! remove
void linkedlist:: remove()
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete(temp);
}

int main()
{
    linkedlist obj;
    obj.start();
    return 0;
}