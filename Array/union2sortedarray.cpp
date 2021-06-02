#include<bits/stdc++.h>
using namespace std;

// Printing Union and Intersection of two sorted array
// TC = O(n+mlog(n+m))  SC = (n+m)
// here log(n+m) comes from binary searching
// technique = same approach is used in merging two sorted array

// own binary search function to avoid duplicasy
// approach =>before inserting any element in union and intersection we will search it in respective array if it is present or not 
bool bisearch(int arr[], int l,int r , int x)
{
     if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[mid] > x)
            return bisearch(arr, l, mid - 1, x);
        return bisearch(arr, mid + 1, r, x);
    }
    return false;
}

void unionSorted(int a[] , int b[] , int n, int m)
{
    int u[n+m];
    memset(u,0,sizeof(u));
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j])
        {
            if(bisearch(u, 0, k, a[i]))
            {
            i++;
            }
            else{
                u[k++] = a[i];
            }
        }
        else if(a[i]>b[j])
        {
             if(bisearch(u, 0, k, a[i]))
            {
            j++;
            }
            else{
                u[k++] = a[j];
            }
        }
        else 
        {
             if(bisearch(u, 0, k, a[i]))
            {
            i++;
            j++;
            }
            else{
                u[k++] = a[i];
            }
        }
    }
    while(i!=n)
    {
         if(bisearch(u, 0, k, a[i]))
            {
            i++;
            }
            else{
                u[k++] = a[i];
            }
    }
    while(j!=m)
    {
         if(bisearch(u, 0, k, a[i]))
            {
            j++;
            }
            else{
                u[k++] = a[j];
            }
    }
    
    // printing the union array
    for(int p=0;p<k;p++)
    {
        cout<<u[p]<<" ";
    }
    cout<<'\n';
}
 
// for intersection
void intersectionSorted(int a[], int b[], int n, int m)
{
    int inxn[min(n,m)];
    memset(inxn,0,sizeof(inxn));
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j])
            i++;
        else
        if(a[i]>b[j])
            j++;
        if(a[i]==b[j])
        {
            if(bisearch(inxn, 0, k, a[i]))
            {
            i++; j++;
            }
            else{
                inxn[k++] = a[i];
            }
        }
    }
    for(int p=0;p<k;p++)
    {
        cout<<inxn[p]<<" ";
    }
    cout<<'\n';
}
int main()
{
    int a[] = {1,2,3,4,5};
    int b[] = {1,2};
    int n=5,m=2;

    //For union 
    cout<<"Union of these two arrays are ";
    unionSorted(a,b,n,m);

    cout<<"Intersection of these two arrays are ";
    intersectionSorted(a,b,n,m);
    return 0;
}