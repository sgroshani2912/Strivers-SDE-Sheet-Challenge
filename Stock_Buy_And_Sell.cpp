//Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//Brute force approach, TC = O(N^2), SC = O(1)
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int maxi = 0;
    for(int i=0; i<prices.size()-1; i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j]>prices[i]){
                maxi = max(maxi, prices[j]-prices[i]);
            }
        }
    }
    return maxi;
}

//Optimised approach, TC = O(N), SC = O(1)
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i]-mini);
    }
    return maxi;
}
