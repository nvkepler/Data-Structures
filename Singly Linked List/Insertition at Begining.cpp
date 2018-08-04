// Task :
//
// Insert a node at beginning

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
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

        node *create_node(int value);
        void insert(int x);
        void display();
};

node* list :: create_node(int value)
{
    node *temp = new node;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void list :: insert(int x)
{
    node *p;
    p = create_node(x);
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        p -> next = head;
        head = p;
    }
}

void list :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"Empty List"<<endl;
    }
    else
    {
        temp = head;
        cout<<"Elements in Singly Linked List : "<<endl;
        while(temp != NULL)
        {
            cout<<temp -> data<<"\t";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

int main()
{
    list l;
    int x,num;
    cout<<"Enter how many numbers to enter in a Singly Linked List : ";
    cin>>x;

    for(int i=0; i<x; i++)
    {
        cout<<"Enter number : ";
        cin>>num;
        l.insert(num);
    }
    l.display();
    return 0;
}
