//https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_1058184?leftPanelTab=0

#include <bits/stdc++.h>

int next_smallest(int idx, vector<int> &heights){
  for(int i=idx+1; i<heights.size(); i++){
    if(heights[i]<heights[idx]) return i;
  }
  return heights.size();
}

int prev_smallest(int idx, vector<int> &heights){
  for(int i=idx-1; i>=0; i--){
    if(heights[i]<heights[idx]) return i;
  }
  return -1;
}

int largestRectangle(vector < int > & heights) {
  int maxi = INT_MIN;
  for(int i=0; i<heights.size(); i++){
    int n = next_smallest(i, heights);
    int p = prev_smallest(i, heights);
    int ans = (n-p-1) * heights[i];
    maxi = max(maxi, ans);
 
  }
  return maxi;
}
