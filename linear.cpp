#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for (int i = 0;i < n;i++)
    {
        cin>>ar[i];
    }
    int flag = 0;
    int checkvalue;
    cout<<"Enter the value that you want to search: ";
    cin>>checkvalue;
    for (int i = 0;i < n;i++)
    {
        if (ar[i] == checkvalue)
        {
            cout<<"Position of this valeu is: "<<i+1<<endl;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout<<"Not found!";
    }
    return 0;
}

