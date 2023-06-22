#include <bits/stdc++.h>
using namespace std;
void print_array(int ar[], int size)
{
     for (int i = 0; i < size; i++)
     {
          cout << ar[i] << " ";
     }
     cout << endl;
}
int main()
{
     int n;
     cin >> n;
     int ar[n];
     for (int i = 0; i < n; i++)
     {
          cin >> ar[i];
     }
     cout << "Befor sorting: ";
     print_array(ar,n);
     int max = INT_MIN;
     for (int i = 0; i < n; i++)
     {
          if (ar[i] > max)
          {
               max = ar[i];
          }
     }
     int count[max + 1];
     for (int i = 0; i <= max; i++)
     {
          count[i] = 0;
     }
     for (int i = 0; i < n; i++)
     {
          count[ar[i]]++;
     }
     cout << "Frequency of array element: ";
     print_array(count, max + 1);

     for (int i = 1; i <= max; i++)
     {
          count[i] += count[i - 1];
     }
     cout << "Cumulative sum: ";
     print_array(count, max + 1);

     int sorted_array[n];
     for (int i = n - 1; i >= 0; i--)
     {
          count[ar[i]]--;
          int k = count[ar[i]];
          sorted_array[k] = ar[i];
     }

     cout << "After sorting: ";
     print_array(sorted_array, n);

     return 0;
}
