// https://rb.gy/49ugs

#include <bits/stdc++.h> 

void solve(int n, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> temp, int curr){
    //Exclude
	int num = accumulate(temp.begin(), temp.end(), 0);
	if(num==target){
		ans.push_back(temp);
	}
    
    
    //Include without duplicate elements
    for( int i=curr; i<n; i++){
        if(i > curr && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(n, arr, target, ans, temp, i+1);
        temp.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;

    solve(n, arr, target, ans, temp, 0);
    return ans;
}

