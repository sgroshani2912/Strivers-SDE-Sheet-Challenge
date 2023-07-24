//Problem link - http://rb.gy/u4o1i

//Brute force approach using three loops
#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	set<vector<int>> ans;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				if(arr[i]+arr[j]+arr[k] == K){
					vector<int> temp = {arr[i], arr[j], arr[k]};
					sort(temp.begin(), temp.end());
					ans.insert(temp);
				}
			}
		}
	}
	vector<vector<int>> result(ans.begin(), ans.end());
	return result;
}

// Using Two loops and a hash set
#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	set<vector<int>> ans;
	
	for(int i=0; i<n; i++){
		set<int> s;
		for(int j=i+1; j<n; j++){
			int sum = arr[i]+arr[j];
			if(s.find(K-sum) != s.end()){
				vector<int> temp = {arr[i], arr[j], K-sum};
				sort(temp.begin(), temp.end());
				ans.insert(temp);
			}
			s.insert(arr[j]);
		}
	}
	vector<vector<int>> result(ans.begin(), ans.end());
	return result;
}

//Optimal approach
#include <bits/stdc++.h> 
//Brute force approach using three loops
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for(int i=0; i<n; i++){
		if(i>0 && arr[i]==arr[i-1]) continue;

		int j=i+1; 
		int k=n-1;
		while(j<k){
			if(arr[i]+arr[j]+arr[k]==K){
				vector<int> temp = {arr[i],arr[j],arr[k]};
				ans.push_back(temp);
				j++;
				k--;
				while(arr[j]==arr[j-1]) j++;
                while(arr[k]==arr[k+1]) k--;
			}
			else if(arr[i]+arr[j]+arr[k]<K) {
				j++;
				while(arr[j]==arr[j-1]) j++;
			}	
			else{
				k--;
				while(arr[k]==arr[k+1]) k--;
			} 
		}
	}
	
	return ans;
}

