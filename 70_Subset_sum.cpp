// https://www.codingninjas.com/studio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h>

void solve(vector<int> &num, int curr, vector<int> &ans, int sum ){
	if(curr==num.size()){
		ans.push_back(sum);
		return;
	}
	//Include
	solve(num, curr+1, ans, sum+num[curr]);

	//Exclude
	solve(num, curr+1, ans, sum);

	return;
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	solve(num, 0, ans, 0 );
	sort(ans.begin(), ans.end());
	return ans;	
}
