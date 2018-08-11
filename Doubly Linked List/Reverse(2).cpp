// Task :
//
// Reverse of Doubly Linked List

#include <iostream>
using namespace std;

struct node
{
    struct node* previous;
    int data;
    struct node* next;
};

class list
{
    node *head, *tail;
    public:
        list()
        {
            head = NULL;
            tail = NULL;
        }

        node *create_node(int);
        void insert(int);
        void display();
        void reverse();
};

node* list :: create_node(int value)
{
    node *temp = new node;
    temp -> previous = NULL;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void list :: insert(int value)
{
    node *temp;
    temp = create_node(value);

    if(head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail -> next = temp;
        tail -> next -> previous = tail;
        tail = tail -> next;
    }
}

void list :: display()
{
    node *temp = new node;
    temp = head;

    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

void list :: reverse()
{
    node *temp = new node;
    temp = tail;
    if(head == NULL)
    {
        cout<<"No Element present to reverse"<<endl;
    }
    else
    {
        temp = tail;
        while(temp != NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp -> previous;
        }
        cout<<endl;
    }
}

int main()
{
    list l;
    int n,num;
    cout<<"Enter List Size : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<"Elements in the List : ";
    l.display();

    cout<<"After Reversing : ";
    l.reverse();

    return 0;
}
