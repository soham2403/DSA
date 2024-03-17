#include <bits/stdc++.h>
using namespace std;
// map
/*
Using & ensures that you're directly accessing the elements in the map, avoiding unnecessary copies and improving performance, while also ensuring that modifications made to the iterator directly affect the elements in the map, maintaining correctness.
*/
vector<int> sortedArrayBrute(vector<int> a, vector<int> b)
{
    vector<int> Union;
    map<int, int> MAP;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++)
        MAP[a[i]]++;
    for (int i = 0; i < m; i++)
        MAP[b[i]]++;

    for (auto &it : MAP)
    {
        Union.push_back(it.first);
    }
    return Union;
}
// set
vector<int> sortedArrayBetter(vector<int> a, vector<int> b)
{
    vector<int> Union;
    int n = a.size(), m = b.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }
    for (auto it : s)
    {
        Union.push_back(it);
    }
    return Union;
}

vector<int> sortedArrayOptimal(vector<int> a, vector<int> b)
{
    vector<int> Union;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    // run the loop till any one array run out
    while (i < n && j < m)
    {
        //find the smaller and add in Union
        if (a[i] <= b[j])
        {
            // check if the value Union array is zero or its equal to a[i]

            if (Union.size() == 0 || Union.back() != a[i])
            {
                Union.push_back(a[i]);
            }
            i++;
        }
        // if b[j]>a[i]

        else
        {
            if (Union.size() == 0 || Union.back() != b[j])
            {
                Union.push_back(b[i]);
            }
            j++;
        }
    }

    while (j < m)
    {
        if (Union.back() != b[j])
        {
            Union.push_back(b[j]);
        }
        j++;
    }
    while (i < n)
    {
        if (Union.back() != a[i])
        {
            Union.push_back(a[i]);
        }
        i++;
    }

    return Union;
}
int main()
{
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    // vector<int> Union = sortedArrayOptimal(a, b);
    // vector<int> Union = sortedArrayBetter(a, b);
    vector<int> Union = sortedArrayBrute(a, b);

    for (auto it : Union)
    {
        cout << it << " ";
    }

    return 0;
}