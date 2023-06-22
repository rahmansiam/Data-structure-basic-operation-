#include<bits/stdc++.h>
using namespace std;
void printArray(int *ar,int size)
{
    for (int i = 0;i < size;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
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
    cout<<"Before soting: ";
    printArray(ar,n);
    cout<<endl;
    //Bubble sort impleamentation.
    for (int i = 1;i < n;i++)
    {   
        int flag = 0;
        cout<<"Iteration NO:"<<i<<endl;
        for (int j = 0;j < n-i;j++)
        {
            if (ar[j] > ar[j+1])
            {
                int tmp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = tmp;
                flag = 1;
            }
            printArray(ar,n);
        }
        cout<<endl;
        if (flag == 0)
        {
            break;
        }
    }
    cout<<"After sorting: ";
    printArray(ar,n);
    return 0;

}