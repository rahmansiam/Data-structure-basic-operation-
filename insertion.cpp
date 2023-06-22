#include<bits/stdc++.h>
using namespace std;
void print_array(int *ar,int size)
{
    for (int i = 0;i < size;i++)
    {
        cout<<ar[i]<<" ";
    }
}
int main()
{   
    int n;
    cin>>n;
    int ar[n];
    for (int i = 0;i < n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Before insertion: ";
    print_array(ar,n);
    cout<<endl;
    int value,position;
    cout<<"Enter the position of insert: ";
    cin>>position;
    cout<<"Enter the value you want to insert: ";
    cin>>value;
    if (position < 0 || position > n)
    {
        cout<<"Invalid index!";
        return 0;
    }
    else
    {   //For sorted array we can use this techniqe:

        // for (int i = n-1;i >= position;i--)
        // {                                                
        //     ar[i+1] = ar[i];                   
        // }
        // ar[position] = value;

        //For Unsorted array:
        ar[n] = ar[position];
        ar[position] = value;
    }
    cout<<"After insertion: ";
    print_array(ar,n+1);
    return 0;
}