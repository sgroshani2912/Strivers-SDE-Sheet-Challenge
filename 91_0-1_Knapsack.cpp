// https://rb.gy/gsies

//Recursion + memoisation
#include <bits/stdc++.h>

int solve(vector<int> &values, vector<int> &weights, int n, int w, int i, vector<vector<int>> &dp){
	if(w <= 0 || i==n){
		return 0;
	}
	if(dp[i][w] != -1){
		return dp[i][w];
	}

	if(weights[i] <= w ){
		int exc = solve(values, weights, n, w, i+1, dp);
		int inc = values[i] + solve(values, weights, n, w-weights[i], i+1, dp);
		return dp[i][w] =  max(exc, inc);
	}
	else{
		return dp[i][w] = solve(values, weights, n, w, i+1, dp);
	}

}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1, vector<int>(w+1,-1));
	int ans = solve(values, weights, n, w, 0, dp);
	return ans;
}

//Recursion
#include <bits/stdc++.h>

int solve(vector<int> &values, vector<int> &weights, int n, int w, int i){
	if(w <= 0 || i==n){
		return 0;
	}

	if(weights[i] <= w ){
		int exc = solve(values, weights, n, w, i+1);
		int inc = values[i] + solve(values, weights, n, w-weights[i], i+1);
		return max(exc, inc);
	}
	else{
		return solve(values, weights, n, w, i+1);
	}

}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	int ans = solve(values, weights, n, w, 0);
	return ans;
}
