#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int ar[],int n,int current)
{
    int largest = current;
    int leftChild = 2*current+1;
    int rightChild = 2*current+2;
    if (leftChild < n && ar[leftChild] > ar[largest])
    {
        largest = leftChild;
    }
    if (rightChild < n && ar[rightChild] > ar[largest])
    {
        largest = rightChild;
    }
    if (largest != current)
    {
        swap(ar[current],ar[largest]);
        heapify(ar,n,largest);  
    }
}
void heapSort(int ar[],int size)
{
    for (int i = size-1;i >= 0;i--)
    {
        swap(ar[0],ar[i]);  
        heapify(ar,i,0);
    }
}

void printArray(int ar[],int size)
{
    cout<<endl;
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
    cout<<"Before Heapify:";
    printArray(ar,n);
    int nonLeafStartNode = (n/2)-1;
    for (int i = nonLeafStartNode;i >= 0;i--)
    {
        heapify(ar,n,i);
    }
    cout<<"After Heapify:";
    printArray(ar,n);

    heapSort(ar,n);
    cout<<"After Heapsort:";
    printArray(ar,n);
    return 0;
}