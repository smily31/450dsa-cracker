#include<bits/stdc++.h>
using namespace std;

// move all negative elements of array to beginning

// two pointer approach -> TC ->O(n)    AS-O(1)
// Approach 2 -> partition process of quicksort
int main()
{
    int a[] ={-12,11,-13,-5,6,-7,5,-3,-6};
    int n=sizeof(a)/sizeof(a[0]);
    int low=0, high=n-1;
    while(low<=high)
    {
        if(a[low]>0)
        {
            swap(a[low],a[high]);
            high--;
        }
        else
        {
            low++;
        }
    }
    cout<<"After shifting the required array is \n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}