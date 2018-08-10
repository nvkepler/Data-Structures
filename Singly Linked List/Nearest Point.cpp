// Task :
//
// Find the nearest point

#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    float x;
    float y;
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

        node *create_node(float,float);
        void insert(float,float);
        void display();
        void check(float,float);
};

node* list :: create_node(float no1,float no2)
{
    node *temp = new node;
    temp->x = no1;
    temp->y = no2;
    temp->next = NULL;
    return temp;
}

void list :: insert(float no1,float no2)
{
    node *temp;
    temp = create_node(no1,no2);
    if(head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
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
            cout<<"X : "<<temp->x<<" "<<"Y : "<<temp->y<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
}

void list :: check(float a,float b)
{
    node *temp = new node;
    temp = head;
    float m,n,o,p,distance;
    float min = 9999;

    if(head == NULL)
    {
        cout<<"No Elements in the list to check"<<endl;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            m = temp->x;
            n = temp->y;
            distance = sqrt(((m-a)*(m-a)) + ((n-b)*(n-b)));

            if(distance < min)
            {
                min = distance;
                o = m;
                p = n;
            }

            temp = temp->next;
        }

        cout<<"Minimum Distance : "<<min<<endl;
        cout<<"Data is Close for X : "<<o<<"   Y : "<<p<<endl;
    }
}

int main()
{
    list l;
    int n,count = 0;
    float num1,num2;
    cout<<"Enter List Size : ";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cout<<"Enter X : ";
        cin>>num1;
        cout<<"Enter Y : ";
        cin>>num2;
        if(count<i)
        {
            cout<<"*******************************"<<endl;
            count++;
        }
        l.insert(num1,num2);
    }

    l.display();

    cout<<endl;

    float a,b;
    
    cout<<"Enter First Point : ";
    cin>>a;
    cout<<"Enter Second Point : ";
    cin>>b;

    l.check(a,b);

    return 0;
}
