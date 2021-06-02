// Not done 
#include<bits/stdc++.h>
using namespace std;

// Minimise the height between tower 
int main()
{
    int arr[] = {1,5,8,10};
    int l = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    sort(arr,arr+l);
    int chng[l];
    int diff = -1;
    int low=0,high=l-1;
    int mid=l/2;
    while(low<=high);
    {
        arr[low]+=k;
        if(arr[high]-k>0)
            arr[high]-=k;
        else
            arr[high]+=k;
    }
    sort(arr,arr+l);
    cout<<arr[l-1]-arr[0]<<'\n';
    return 0;
}
