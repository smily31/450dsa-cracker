#include<bits/stdc++.h>
using namespace std;

//Minimum no jumps to reach end of the array

int main()
{
    int arr[]={1,3,5,8,9,2,6,7,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0, count=0;
    while(i < n-1)
    {
        count++;
        i+=arr[i];
    }
    cout<<count<<'\n';
    return 0;
}