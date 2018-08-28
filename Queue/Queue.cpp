// Task :
//
// Queue with Array

#include <iostream>
using namespace std;

class Queue
{
    int front, rear, MAX;
    public:
        int arr[20];

        Queue()
        {
            front = -1;
            rear = -1;
            MAX = 20;
        }

        void push(int);
        void display();
        void pop();
};

void Queue :: push(int value)
{
    if(rear == MAX-1)
    {
        cout<<"Overflow Occured"<<endl;
    }
    else if(front == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = value;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}

void Queue :: pop()
{
    if(front == -1)
    {
        cout<<"No Element to POP"<<endl;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void Queue :: display()
{
    if(rear > -1)
    {
        cout<<"Final Result : ";
        for(int i=front; i<=rear; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"No Elements to show"<<endl;
    }
}

int main()
{
    Queue s;
    int n,choice,number;
    cout<<"Enter Total Steps to perform(push/pop) : ";
    cin>>n;

    cout<<"***************  MENU  ***************"<<endl;
    cout<<"Press 1 to PUSH"<<endl;
    cout<<"Press 2 to POP"<<endl;
    cout<<"**************************************"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Your Choice : ";
        cin>>choice;

        while(choice < 1 || choice > 2)
        {
            cout<<"Wrong Choice Entered... TRY AGAIN"<<endl;
            cout<<"Enter Your Choice : ";
            cin>>choice;
        }

        if(choice == 1)
        {
            cout<<"Enter Number : ";
            cin>>number;
            s.push(number);
            cout<<"*****************************"<<endl;
        }
        else if(choice == 2)
        {
            s.pop();
            cout<<"*****************************"<<endl;
        }
    }

    s.display();

    return 0;
}
