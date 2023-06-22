#include <bits/stdc++.h>
using namespace std;

/*
3
3
1 4 7
2
3 5
3
2 6 7
*/




int main()
{
    int k;
    cin >> k;
    vector<vector<int>> allValues(k);

    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;
        allValues[i] = vector<int>(size);
        for (int j = 0; j < size; j++)
        {
            cin >> allValues[i][k];
        }
    }
    
}


