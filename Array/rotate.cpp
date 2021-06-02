#include<bits/stdc++.h>
using namespace std;

// Cyclically rotate an array by one 
// Approach-> store last element in a variable shift the array by one then insert the stored element at first position
// TC -O(n)     SC-O(1)

int main()
{
    int arr[]={1,2,3,4,5};
    int l = sizeof(arr)/sizeof(arr[0]);
    int t = arr[l-1];
    for(int i=l-2;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=t;

    for(int i=0;i<l;i++)
    cout<<arr[i]<<" ";
    cout<<'\n';
    return 0;
}