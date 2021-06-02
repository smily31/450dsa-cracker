#include<bits/stdc++.h>
using namespace std;

// here we have to reverse an existing array 
// TC = O(n)
// swapping technique
void iteration(int a[], int n)
{
    int s=0,e=n-1;
    while(s<e)
    {
        int t = a[s];
        a[s] = a[e];
        a[e] = t;
        s++;
        e--;
    }
    cout<<"Answer is due to iteration method \n";
}

// same tc and same technique using recursion 
void recur(int a[], int s, int e)
{
    if(s>=e)
    return;
    
    int t = a[s];
    a[s] = a[e];
    a[e] = t;
    recur(a,s+1,e-1);
    cout<<"Answer is due to recursion method \n";
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<"   ";

    cout<<endl;
}
int main()
{
    int arr[] = { 1 ,2 , 3 , 4 , 5, 6, 7 , 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    iteration(arr,n);    // iteration 
    recur(arr,0,n-1);    // recursion

    print(arr,n);

    return 0;
}