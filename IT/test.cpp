#include<iostream>

using namespace std;

//Class node
class node
{
    public:
    int data;
    node* next;

    node()
    {
        data = 0;
        next = NULL;
    }
};
//Class linked list
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
    void insert(int value);
    void remove();
    void display();
};

//---------------------Start Function
void linkedlist:: start()
{
    int ch = 0;
    while(ch != 4)
    {
        cout << "What option will you require" << endl;
        cout << "1.Insert \n 2.Remove \n3.Display"<< endl;
        cout << "Enter your option" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
            int value;
            cout << "Enter the value to be entered" << endl;
            cin >> value;
            insert(value);
            break;

            case 2:
            remove();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            cout << "Wrong Option" << endl;
        }
    }
}

//-----------------Insert Function------------------
void linkedlist :: insert(int value)
{
    node *p = new node;
    p->data = value;

    if (head == NULL)
    {
        head = p;
    }

    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

//---------------------Remove Function--------------------
void linkedlist:: remove()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = head->next;
    delete(head);
    head = temp;
    
}

void linkedlist:: display()
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

//-----------------------Main Function
int main()
{
    linkedlist obj;
    obj.start();
    return 0;
}