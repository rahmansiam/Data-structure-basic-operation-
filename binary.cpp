#include<bits/stdc++.h>
using namespace std;
//Iterate method.
// int binary_search(int ar[],int size,int value)
// {
//     int l = 0,r = size;
//     while (l <= r)
//     {       
//         int mid = (l+r) / 2;
//         if (ar[mid] == value)
//         {
//             return mid;                      
//         }
//         else if (ar[mid] > value)
//         {
//             r = mid - 1;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return -1;  
// }
// Recursive method.
int binarySearch(int ar[],int x,int l,int r)
{
    if (l <= r)
    {
        int mid = (l+r) / 2;
        if (x == ar[mid])
        {
            return mid;
        }
        else if (x > ar[mid])
        {
            binarySearch(ar,x,mid+1,r);
        }
        else
        {
            binarySearch(ar,x,l,mid-1);
        }
    }
    else
    {
        return -1;
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
    int x;
    cout<<"Enter a value for searching: ";
    cin>>x;
    cout<<binarySearch(ar,x,0,n-1);
    
    return 0;
    
}