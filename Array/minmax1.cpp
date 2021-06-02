#include<bits/stdc++.h>
using namespace std;

// Finding minimum and maximum from array using minimum no of comparisons 
// TC = O(n)        for all approaches

// to return minimum and maximum we need structure of pair 
struct Pair
{
    int min;
    int max;
};

// edge case ka dhyan rkhna ki jab array me 1 element ho tb kya ans arr jb 2 ho arr jab 2 se jyada ho 

// Approach 1
// basic linear search aproach bt it will not give minimum no of comparisons 
struct Pair linearsearch(int arr[], int n)
{
    cout<<" The answer is due to linear search method which does not do minimum no of comparison \n";
    struct Pair minmax;
    minmax.min = INT_MAX, minmax.max = INT_MIN;
    if(n==1)
    minmax.min=minmax.max=arr[0];
    else
    if(n==2)
    {
        if(arr[0]>arr[1])
        {
            minmax.max=arr[0];
            minmax.min=arr[1];
        }
        else
        {
            minmax.max=arr[1];
            minmax.min=arr[0];
        }
    }
    else
    {
    for(int i=0;i<n;i++)
    {
        if(arr[i]>minmax.max)
        minmax.max = arr[i];
        else 
        if(arr[i]<minmax.min)
        minmax.min = arr[i];
    }
    }
    return minmax;
}

// Approach 2
// Tournament method - uses divide and conquer technique -> divide the array in two part and then
// independently find min max of two part and then finally compare both and we get result 
// does minimum number of comparison

struct Pair tournamentMethod(int a[], int s, int e)
{
    cout<<"answer is due to d&c method \n";
    struct Pair minmax, mml, mmr;
    if(s==e)
    {
        minmax.min = a[s];
        minmax.max = a[s];
        return minmax;
    }
    else if(e == s+1)
    {
        if(a[s]>a[e])
        {
            minmax.max=a[s];
            minmax.min=a[e];
        }
        else
        {
            minmax.max=a[e];
            minmax.min=a[s];
        }
        return minmax;
    }
    else
    {
        int mid = s+(e-s)/2;
        mml = tournamentMethod(a,s,mid);
        mmr = tournamentMethod(a,mid+1,e);
        if(mml.min<mmr.min)
            minmax.min = mml.min;
        else
            minmax.min = mmr.min;
        if(mml.max>mmr.max)
            minmax.max = mml.max;
        else    
            minmax.max = mmr.max;

        return minmax;
    }

    // if n is power of 2 then it compares 3n/2-2 times else more than that
}

// Approach 3 
// compare pairs 
// array me 2 se start krke 2 consecutive element ko compare krenge then usko min max ke value se compare krenge 

struct Pair comparePair (int a[], int n)
{
    cout<<"Answer is due to compare pair method \n";
    struct Pair minmax;
    int i;
    // yaha egde case n==1||n==2 nhi hai 
    // hmlog pairs me kam kr rhe to edge case even odd rhega 
    if(n%2==0)
    {
        if(a[0]<a[1])
        {
            minmax.min=a[0];
            minmax.max=a[1];
        }
        else
        {
            minmax.min = a[1];
            minmax.max = a[0];
        }
        i=2;
    }
    else
    {
        minmax.min = minmax.max = a[0];
        i=1;
    }
    while(i<n-1)
    {
        if(a[i]<a[i+1])
        {
           if(a[i]<minmax.min)
            minmax.min = a[i];
           if(a[i+1]>minmax.max)
            minmax.max = a[i+1];
        }
        else
        {
            if(a[i]>minmax.max)
             minmax.max = a[i];
            if(a[i+1]<minmax.min)
             minmax.min = a[i+1];
        }
        i+=2;
    }
    return minmax;
} // even me 3n/2-2 comparisons  ,  odd me 3(n-1)/2

int main()
{
    int a[] = {2,0};
    int n = sizeof(a)/sizeof(a[0]);
    // struct Pair minmax = linearsearch(a,n);
    // struct Pair minmax = tournamentMethod(a,0,n-1);
    struct Pair minmax = comparePair(a,n);
    cout<<"Max element is "<<minmax.max<<'\n'<<"Min element is "<<minmax.min<<'\n';
    return 0;
}
