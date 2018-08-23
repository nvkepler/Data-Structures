#include <iostream>
using namespace std;

void tower(int a, char from, char aux, char to)
{
    if(a == 1)
    {
        cout<<"Move Disc : "<<a<<" from "<<from<<" to "<<to<<endl;
    }
    else
    {
        tower(a-1,from,to,aux);
        cout<<"Move Disc : "<<a<<" from "<<from<<" to "<<to<<endl;
        tower(a-1,aux,from,to);
    }
}

int main()
{
    int n;
    cout<<"Enter No. of Discs : ";
    cin>>n;
    tower(n,'a','b','c');
    return 0;
}
