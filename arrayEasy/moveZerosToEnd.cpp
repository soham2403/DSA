#include <bits/stdc++.h>
using namespace std;

void optimal(vector<int> &arr,int n){
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }

        /*
        mistake dont know why it didnt work.
        if(arr[i]==0){
            j++;
        }
        else{
            swap(arr[i],arr[j]);
        }
        */
    }
    
}
void brute(vector<int> &arr, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }

    int tempn= temp.size();

    for (int i = 0; i < n; i++)
    {
        if(i>=tempn){
            arr[i] =0;
        }
        else{
            arr[i] = temp[i];
        }
    }
    
}
int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = arr.size();

    // brute(arr,n);
    optimal(arr,n);
    for(auto it :arr){
        cout<<it<<"";
    }
    return 0;
}
