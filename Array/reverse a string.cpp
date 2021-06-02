#include<bits/stdc++.h>
using namespace std;

// here we have to reverse a string -> simple way to create new string and insert char in reverse way
// TC = O(n)    SC = O(1)

string reversestring (string s)
{
    string rev = "";
    for(int i=s.size()-1; i>=0; i--)
    {
        rev += s[i];
    }
    return rev;
}

int main()
{
    string s = "I am fantastically awesome";

    cout<<"Reverse string is "<<reversestring(s)<<'\n';
    return 0;
}