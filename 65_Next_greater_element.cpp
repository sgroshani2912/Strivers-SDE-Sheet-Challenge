// https://www.codingninjas.com/studio/problems/next-greater-element_670312?leftPanelTab=1

//Brute force, TC = O(N^2), SC = O(1)
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> ans(n, -1);
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[j]>arr[i]){
				ans[i] = arr[j];
				break;
			}
		}
	}
	return ans;
}

//Using stack, TC = O(N), sc = O(1)
#include <bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> ans(n, -1);
	stack<int> st;
	
	int i=n-1;
	while(i>=0){
		if(st.empty()){
			ans[i]=-1;
			st.push(arr[i]);
			i--;
		}
		else{
			if(arr[i]>=st.top()){
				st.pop();
			}
			else{
				ans[i] = st.top();
				st.push(arr[i]);
				i--;
			}
		}
	}
	return ans;
}
