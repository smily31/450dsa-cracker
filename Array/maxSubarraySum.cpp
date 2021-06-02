#include<bits/stdc++.h>
using namespace std;

//you must know the concepts of subarray ie it is contiguous part of subarray
// In this you have to find the maximum sum of subarray 

// To better understand this problem Go here -> https://www.youtube.com/watch?v=0JYgnhnZFcE&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=25

// First approach 
// TC = O(n^3)  SC = O(1) 
int bruteApproach(int arr[], int n)
{
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++)  // this will start point
    {
        for(int j=i;j<n;j++) // and this will end point to find elements of subarray 
        {
            int sum=0;
            for(int k=i;k<j;k++)    // this loop will get elements of each subarray so we directly take sum and compare it with maxSum
            {
                sum+=arr[k];
                maxSum=max(maxSum,sum);
            }
        }
    }
    return maxSum;
}

// Little optimised approach 
// using curated sum approach ->create an array of n+1 size and then fill it with curated sums
// TC = O(n^2)   SC = O(n+1)
int curatedSum(int arr[], int n)
{
    int maxSum = INT_MIN;
    int curSum[n+1];   // declaring array to store curated sums of array
    curSum[0]=0; 
    for(int i=1;i<=n;i++)
        curSum[i]=curSum[i-1]+arr[i-1];
    
    for(int i=1;i<n;i++)   // starting point in curSum array
    {
        int sum=0;
        for(int j=0;j<n;j++) // ending point in curSum array 
        {
            sum=curSum[i]-curSum[j];    // subtracting them will give sum of all subarrays
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

//Most optimsed approach -> Kadane's Algorithm
// TC = O(n)   SC =O(1)
int kadaneAlgo(int arr[],int n)
{
    int curSum =0;   //will store only positive contiguous segment sum
    int maxSum =INT_MIN;
    for(int i=0;i<n;i++)
    {
        curSum += arr[i];
        maxSum = max(maxSum,curSum);
        if(curSum < 0)
            curSum = 0;
    }
    return maxSum;
}

// main function
int main()
{
    int a[]={-1,4,-6,7,-4};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<" Maximum sum of subarray is "<<kadaneAlgo(a,n)<<'\n';
    return 0;
}