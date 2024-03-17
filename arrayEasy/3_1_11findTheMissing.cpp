#include <bits/stdc++.h>
using namespace std;

int missingNumberBrute(vector<int> &a, int N)
{
    // represent the number 1 -> N.
    for (int i = 1; i <= N; i++)
    {
        // flag to check if present or not.
        bool flag = false;
        // linear search in array to find missing element.
        for (int j = 0; j < N - 1; j++)
        {
            cout << i << a[j] << flag << "\n";
            if (a[j] == i)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            return i;
        }
    }
}
int missingNumberBetter(vector<int> &a, int N)
{
    // why n+1 is the size of hash.
    int hash[N + 1] = {0};
    // iterrate throught inp vector and mark 1 if found.
    // hash will have key and value[frequency].
    for (int i = 0; i < N - 1; i++)
    {
        // is used to mark 1
        hash[a[i]]++;
    }

    // traveerse through the hash and find zero.
    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
            return i;
    }
}
int missingNumberOpti1(vector<int> &a, int N)
{
    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += a[i];
    }
    return ((N * (N + 1)) / 2) - sum;
}
/*
Two important properties of XOR are the following:
1] a ^ a = 0. 
2] 0 ^ a = a. 

Dry run:

Assume the given array is: {1, 2, 4, 5} and N = 5.
XOR of (1 to 5) i.e. xor1 = (1^2^3^4^5)
XOR of array elements i.e. xor2 = (1^2^4^5)
XOR of xor1 and xor2 = (1^2^3^4^5) ^ (1^2^4^5)
			= (1^1)^(2^2)^(3)^(4^4)^(5^5)
			= 0^0^3^0^0 = 0^3 = 3.
The missing number is 3.

*/
int missingNumberOpti2(vector<int> &a, int N)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < N - 1; i++)
    {

        xor1 ^= a[i];
        xor2 ^= i + 1;
    }
    xor2 = xor2 ^ N;

    return xor1 ^ xor2;
}

int main()
{
    vector<int> a = {1, 2, 4, 5};
    // why +1 in size ?= because one number is missing and we have to find that out.
    int N = a.size() + 1;
    // cout<<missingNumberBrute(a,N);
    // cout<<missingNumberBetter(a,N);
    // cout<<missingNumberOpti1(a,N);
    // cout<<missingNumberOpti2(a,N);

    return 0;
}