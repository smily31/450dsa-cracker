#include<bits/stdc++.h>
using namespace std;

// finding kth max and min 
// brute approach -array
// optimsed approach -heap or quickselect(algorithm)  --this in next code--

int main()
{
    int arr[] = { 2, 5, 0, 100, 3, -2, 31, 15 , 10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    sort(arr, arr+n);
    cout<<"Kth minimum no of array is "<<arr[k-1]<<'\n';
    cout<<"Kth maximum no of array is "<<arr[n-k]<<'\n';
    return 0;
}