#include<bits/stdc++.h>
using namespace std;

// we have to sort arrayof 0s,1s,2s without using any sorting technique 
// here we will use 3 pointer technique
// before low all are 0s
// between low and mid are 1s
// after high are 2s
// TC = O(n)   SC = (n)

// isme ek basic simple counting approach hota hai -> jisme no of 0s 1s 2s count krke array me update kr dete hai 
// approach -> mid ko 0 se high tk iterate krenge arr acc to condn swap krenege
int main()
{
    int a[]={2,1,0,2,1,0,2,1,1,0};
    int n = sizeof(a)/sizeof(a[0]);
    int low=0, mid=0, high=n-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else
        if(a[mid]==2)
        {
            swap(a[high],a[mid]);
            high--;
        }
        else 
            mid++;
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    
    return 0;
}