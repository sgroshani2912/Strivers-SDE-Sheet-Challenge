// https://rb.gy/amtq0

//Using sets
#include <bits/stdc++.h> 

void solve(vector<int> &arr, int n, int curr,vector<int> temp,set<vector<int>> &s){
    if(curr>=n){
        sort(temp.begin(), temp.end());
        s.insert(temp);
        return;
    }

    //Exclude
    solve(arr, n, curr+1, temp, s);

    //Include
    temp.push_back(arr[curr]);
    solve(arr, n, curr+1, temp, s);
    temp.pop_back();

    return;

}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> s;
    vector<int> temp;
    solve(arr, n, 0, temp, s);
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

//Without using sets
#include <bits/stdc++.h> 

void solve(int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> temp, int curr){
    //Exclude
    ans.push_back(temp);
    
    //Include without duplicate elements
    for( int i=curr; i<n; i++){
        if(i > curr && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(n, arr, ans, temp, i+1);
        temp.pop_back();
    }
    return;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;

    solve(n, arr, ans, temp, 0);
    return ans;
    
}
