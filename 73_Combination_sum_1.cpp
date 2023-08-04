// https://rb.gy/65gjv
#include <bits/stdc++.h>

void solve(vector<int> arr, int n, int k, int curr, vector<int> temp, vector<vector<int>> &ans){
    if (curr == n){
        int num = accumulate(temp.begin(), temp.end(),0);
        if(num == k){
            ans.push_back(temp);
        }
        return;
    }

    //exclude
    solve(arr, n, k, curr+1, temp, ans);

    temp.push_back(arr[curr]);
    solve(arr, n, k, curr+1, temp, ans);
    temp.pop_back();
    return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(arr, n, k,0, temp, ans);
    return ans;

}
