// https://rb.gy/hug5b

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int, vector<int>, greater<int>> p;
	for(int i=0; i<size; i++){
		if(p.size()<K){
			p.push(arr[i]);
		}
		else{
			if(arr[i]>p.top()){
				p.pop();
				p.push(arr[i]);
			}
		}
	}
	return p.top();
}
