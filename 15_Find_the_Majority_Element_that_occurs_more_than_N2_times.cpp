//Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

//Using sorting, TC = O(NlogN), SC = O(1)
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int cnt = 1;
	int maxi = 0;
	int ele;
	sort(arr, arr+n);
	for(int i=1; i<n; i++){
		if(arr[i]==arr[i-1]){
			cnt++;
			if(cnt>maxi){
				maxi = cnt;
				ele = arr[i];	
			}
	
		}
		else{
			
			cnt = 1;
		}
	}
	if(n==1){
		return arr[0];
	}
	else if(maxi > (int)n/2){
		return ele;
	}
	else{
		return -1;
	}
}

//Optimal approach, TC = O(N), SC = O(1)
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int cnt = 0;
	int ele;;
	
	for(int i=0; i<n; i++){
		if (cnt == 0) {
			cnt++;
			ele = arr[i];
		}

		else if(arr[i]==ele) cnt++;
		else cnt--;
    }

	int cnt_ele = 0;
	for(int i=0; i<n; i++){
		if(arr[i]==ele) cnt_ele++;
	}

	if(cnt_ele > n/2){
		return ele;
	}
	return -1;
}



