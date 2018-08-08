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
    if(temp->data == no)
    {
        head = temp -> next;
        head -> previous = NULL;
        delete temp;
    }
    else
    {
        int flag = 0;
        node *ptr = new node;
        while(temp->data != no)
        {
            ptr = temp;
            if(temp->next == NULL)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(temp->next == NULL)
        {
            ptr->next = NULL;
            delete temp;
        }
        else
        {
            ptr -> next = temp -> next;
            temp->next->previous = temp->previous;
            delete temp;
        }
        if(flag == 1)
        {
            cout<<endl<<"*******Element not present for deletition*******"<<endl<<endl;
        }
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
            cout<<temp -> data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    list l;
    int x,num;
    cout<<"Enter how many numbers to enter in Doubly Linked List : ";
    cin>>x;

    for(int i=0; i<x; i++)
    {
        cout<<"Enter number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<endl<<"Before Deletition : "<<endl;
    l.display();

    int no;
    cout<<"Enter Number to delete : ";
    cin>>no;
    l.delete_element(no);

    cout<<"After Deletition : "<<endl;
    l.display();
    return 0;
}
