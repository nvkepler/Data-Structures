// Task :
//
// Reverse Singly Linked List (Here just inserting elements in beginning and then printing)

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head,int value)
{
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;

    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void display(struct node *head)
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"List is Empty";
    }
    else
    {
        temp = head;
        cout<<"Elements in List are : "<<"\t";
        while (temp != NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    node *head, *tail;
    head = NULL;
    tail = NULL;

    int n,num;
    cout<<"Enter Size of List : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        insert(&head,num);
    }

    display(head);

    return 0;
}
