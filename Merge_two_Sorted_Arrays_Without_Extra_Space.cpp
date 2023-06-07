//Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

//Solution, TC = O(max(N, M)), SC=O(1)
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=m-1;
	int j=n-1;
	int x = m+n -1;
	while(i>=0 && j>=0){
		if(arr1[i] >= arr2[j]){
			arr1[x--] = arr1[i--];
		}
		else{
			arr1[x--] = arr2[j--];

		}
	}
	while(i>=0){
		arr1[x--] = arr1[i--];
	}
	while(j>=0){
		arr1[x--] = arr2[j--];
	}

	return arr1;
	
}
