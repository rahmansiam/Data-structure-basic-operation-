#include<bits/stdc++.h>
using namespace std;
void printArray(int ar[],int size)
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
    cout<<"Before sorting: ";
    printArray(ar,n);
    cout<<endl;
    for (int i = 1;i < n;i++)
    {
        int key = ar[i];
        int j = i-1;
        while (ar[j] > key && j >= 0)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
        
    }
    cout<<"After sorting: ";
    printArray(ar,n);
    return 0;
}