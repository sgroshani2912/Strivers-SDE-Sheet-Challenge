//Problem link - https://shorturl.at/gGT39

//Approach-1 Recursion, TC = exponential, SC= exponential
#include <bits/stdc++.h>
void solve(int i, int j, int m, int n, int &ans){
	if(i==m-1 && j==n-1){
		ans++;
		return;
	}

	if(i>=m || j>=n){
		return;
	}

	//Option 1
	solve(i+1, j, m, n, ans);

	//Option 2
	solve(i, j+1, m, n, ans);

	return;



}
int uniquePaths(int m, int n) {
	int ans = 0;
	solve(0,0,m,n,ans);
	return ans;
}

//Approach 2, dynamic programming, TC = O(N*M), SC = O(N*M)
#include <bits/stdc++.h>
int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
	if(i==m-1 && j==n-1) return 1;

	if(i>=m || j>=n) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	//Option 1 + Option 2
	return dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);	

}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	int ans = solve(0,0,m,n,dp);
	return ans ;
}
