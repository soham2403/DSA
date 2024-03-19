#include <bits/stdc++.h>
using namespace std;

int brute1(vector<int> arr, int n, int k)
{
}

int brute2(vector<int> arr, int n, int k)
{
  int sums;
  int length = 0;
  for (int i = 0; i < n; i++)
  {
    sums = 0;
    for (int j = i; j < n; j++)
    {
      sums += arr[j];
      if (sums == k)
      {
        length = max(length, (j - i) + 1);
      }
    }
    // cout << sums << "\n";
  }

  return length;
}

// using hash map
int better(vector<int> arr, int n, int k)
{
  map<long long, int> preSum;
  int len = 0;
  long long sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
    if (sum == k)
    {
      len = max(len, i + 1);
    }

    long long rem = sum - k;
    if (preSum.find(rem) != preSum.end())
    {
      len = max(len, i - preSum[rem]);
    }

    // edge case
    if (preSum.find(sum) == preSum.end())
    {
      preSum[sum] = i;
    }
  }
  return len;
}

/*
  sum = continusly add value of elements.



*/
// not completed
int optimal(vector<int> arr, int n, int k)
{
  int length = 0;
  int l = 0, r = 0;
  int sum = arr[0];

  while (r < n)
  {
    if (sum > k)
    {
      sum -= arr[l];
      l++;
    }
    else if (sum == k)
    {
      length = max(length, (r - l) + 1);
      r++;
    }
    else
    {
      sum += arr[r];
    }
  }
  return length;
}
int main()
{
  int k = 2;
  vector<int> arr = {1, 2, 1, 3};
  int n = arr.size();
  cout << brute1(arr, n, k);

  // cout<<brute2(arr,n,k);
  // cout << optimal(arr, n, k);
  // cout<< better(arr,n,k);
  return 0;
}
