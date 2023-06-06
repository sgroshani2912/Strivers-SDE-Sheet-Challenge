//Problem statement - Write a program to generate pascal's triangle 

//Optimal Approach for printing the pascal's triangle, TC = O(N^2), SC = 0(1)
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  
  for(int i=1; i<=n; i++){
    vector<long long int> tmp;
    long long int prev = 1;
    tmp.push_back(prev);
    for(int j=1; j<i; j++){
      long long int curr = (prev*(i-j))/j;
      tmp.push_back(curr);
      prev = curr;
    }
    ans.push_back(tmp);

  }
  return ans;
}
