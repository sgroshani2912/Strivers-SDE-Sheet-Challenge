// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

//Using frequency array, TC = O(N), SC = O(N)
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	
	//Using frequency map concept
	
	unordered_map<int, int> mp;
	for(int i=0; i<n; i++){
		mp[arr[i]]++;
	}
	int m;
	int r;
	for(int i=1; i<=n; i++){
		if(mp.find(i)!= mp.end()){
			if(mp[i]>1) r = i;
		}
		else{
			m = i;
		}
	}
	pair<int,int> ans = make_pair(m,r);
	return ans;
	
}
