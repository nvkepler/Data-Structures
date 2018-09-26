// Task :
//
// Perform Selection Sort

#include <iostream>
using namespace std;

int main()
{
    int temp,n;
    cout<<"Enter List Size : ";
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Element : ";
        cin>>arr[i];
    }

    // ***********************************************************

    cout<<endl<<"***********************************************"<<endl;
    cout<<"Before Sorting : ";

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }

    cout<<endl;

    // ***********************************************************

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // ***********************************************************

    cout<<"After Sorting : ";

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }

    cout<<endl<<"***********************************************"<<endl;

}
