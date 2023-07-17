//Problem link - https://shorturl.at/JRX35

//Optimal Approach, TC = O(N), SC = O(N)
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  
  unordered_map<int, int> m;
  int n = arr.size();
  int sum = 0;
  int ans = 0;
  for(int i=0; i<n; i++){
    sum+=arr[i];
    if(sum==0){
      ans = max(ans, i+1);
    }
    else{
      if(m.find(sum) != m.end()){
        ans = max(ans, i-m[sum]);
      }
      else{
        m[sum] = i;
      }
    }
  }
  return ans;

}
