// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

//Brute Force approach, TC = O(N^2), SC = O(1)
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = 0;
    
    for(int i=0; i<n; i++){
        long long sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxi = max(sum, maxi);
        }
        
    }
    return maxi;
}

//Kadane's Algorithm, TC=O(N), SC = O(1)
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
   long long maxi = INT_MIN;
   long long sum = 0;

   for(int i=0; i<n; i++){
       sum += arr[i];
       if(sum<0){
           sum=0;
       }
       maxi = max(maxi, sum);
       
   }
   return maxi;


}
