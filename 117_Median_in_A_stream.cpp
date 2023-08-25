// http://rb.gy/7u0ip

#include <bits/stdc++.h>

int signum(int a, int b){
	if(a > b){
		return 1;
	}
	else if(a < b){
		return -1;
	}
	else{
		return 0;
	}
}

int find_median(priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int  element, int &median ){

	switch(signum(max_heap.size(), min_heap.size())){
		case 0:
		if(element > median){
			min_heap.push(element);
			median =  min_heap.top();
		}
		else{
			max_heap.push(element);
			median = max_heap.top();

		}
		break;

		case 1:
		if(element > median){
			min_heap.push(element);
			median = (min_heap.top() + max_heap.top())/2;
		}
		else{
			min_heap.push(max_heap.top());
			max_heap.pop();
			max_heap.push(element);
			median = (min_heap.top() + max_heap.top())/2;
		}
		break;

		case -1:
		if(element > median){
			max_heap.push(min_heap.top());
			min_heap.pop();
			min_heap.push(element);
			median = (min_heap.top() + max_heap.top())/2;
		}
		else{
			max_heap.push(element);
			median = (min_heap.top() + max_heap.top())/2;
		}
		break;
	}

}

vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int> ans;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int median = -1;
	
	for(int i=0; i<n; i++){
		find_median(max_heap, min_heap, arr[i], median);
		ans.push_back(median);
		
	}

	return ans;
}
