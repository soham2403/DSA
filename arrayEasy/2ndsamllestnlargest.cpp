#include <bits/stdc++.h>
using namespace std;
// brute force
void getElements(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array
    sort(arr.begin(), arr.end());
    int small = arr[1];
    int large = arr[n - 2];
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}
// optimal approach
void secLargestNSmallest2(vector<int> &arr, int n)
{
    int max = INT_MIN, secMax = INT_MIN;
    int min = INT_MAX, secMin = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            secMin = min;
            min = arr[i];
        }
        else if (arr[i] < secMin && arr[i] != min)
        {
            secMin = arr[i];
        }

        if (max < arr[i])
        {
            secMax = max;
            max = arr[i];
        }
        else if (arr[i] > secMax && arr[i] != max)
        {
            secMax = arr[i];
        }
    }
    cout << "second mininum = " << secMin << "second largest = " << secMax;
}
// better aproach
void secLargestNSmallest(vector<int> &arr, int n)
{
    int max = arr[0], secMax = arr[0];
    int min = INT_MAX, secMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ' << secMax << '\n';
        if (arr[i] > secMax && arr[i] != max)
        {
            secMax = arr[i];
        }

        if (arr[i] < secMin && arr[i] != min)
        {
            secMin = arr[i];
        }
    }

    cout << "second mininum = " << secMin << "second largest = " << secMax;
}
int main()
{
    // Find Second Smallest and Second Largest Element in an array
    vector<int> arr = {3,4,1,3,65,5,4,23,3,2,};
    int n = arr.size();
    // secLargestNSmallest2(arr, n);
    getElements(arr,n);
    return 0;
}