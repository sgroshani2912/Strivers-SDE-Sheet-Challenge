//Problem link - https://shorturl.at/etEKL    


//Brute force approach, TC = O(N^2), SC = O(1)
#include <bits/stdc++.h> 
int reversePairs(vector<int> &arr, int n){
	int ans = 0;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++ ){
			if(arr[i]>2*arr[j]) ans++;
		}
	}	
	return ans;
}


//Optimal approach, TC = O(2*NLOGN), SC = O(N)
#include <bits/stdc++.h> 

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int count_pairs(vector<int> &arr, int low, int mid, int high){
	int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int merge_sort(vector<int> &arr, int low, int high){
	//Cnt variable stores the number of pairs 
	int cnt = 0;
	if(low>=high) return cnt;
	int mid = (high+low)/2;
	cnt+= merge_sort(arr, low, mid );
	cnt+= merge_sort(arr, mid+1, high);
	cnt+= count_pairs(arr, low, mid, high);
	merge(arr, low, mid, high);
	return cnt;
	
}
int reversePairs(vector<int> &arr, int n){
	int ans = merge_sort(arr, 0, n-1);
	return ans;	
}
