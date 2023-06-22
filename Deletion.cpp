#include<bits/stdc++.h>
using namespace std;
void print_array(int ar[],int size)
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
    cout<<"Before deletion: ";
    print_array(ar,n);
    cout<<endl;
    //Deletion operation.
    int position;
    cout<<"Enter the position of the value that you want to delet: ";
    cin>>position;
    if (position < 0 || position > n-1)
    {
        cout<<"Ivalid position!";
        return 0;
    }
    //If position of value is located in last index(size-1).
    if (position == n-1)
    {
        n--;
    }
    // If position value is located in start or middle index.
    else
    {
        for (int i = position+1;i < n;i++)
        {
            ar[i-1] = ar[i];
        }
        n--;
    }
    cout<<"After deletion: ";
    print_array(ar,n);
    return 0;
}