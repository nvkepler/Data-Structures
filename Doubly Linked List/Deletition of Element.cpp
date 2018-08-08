// Task :
//
// Deletition of element in Doubly Linked List

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

        node* create_node(int);
        void insert(int);
        void display();
        void delete_element(int);
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
    node *ptr;
    ptr = create_node(value);
    if(head == NULL)
    {
        head = ptr;
        tail = head;
    }
    else
    {
        tail -> next = ptr;
        ptr -> previous = tail;
        tail = ptr;
    }
}

void list :: delete_element(int no)
{
    node *temp = new node;
    temp = head;
    while(temp->data != no)
    {
        temp = temp->next;
    }
    temp->next->previous = temp->previous;
    temp->previous->next = temp->next;
    delete temp;
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
            cout<<temp -> data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    list l;
    int x,num,no;
    cout<<"Enter how many numbers to enter in Doubly Linked List : ";
    cin>>x;

    for(int i=0; i<x; i++)
    {
        cout<<"Enter number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<"Enter Number to delete : ";
    cin>>no;
    l.delete_element(no);

    l.display();
    return 0;
}
