// https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277?leftPanelTab=0

#include<bits/stdc++.h>
vector<int> MinimumCoins(int n)
{
    vector<int>ans;
    vector<int>pq={1000,500,100,50,20,10,5,2,1};
       for(auto i:pq){
         while(n!=0 && n>=i){
          ans.push_back(i);
          n-=i;
        }             }
   return ans;
}
