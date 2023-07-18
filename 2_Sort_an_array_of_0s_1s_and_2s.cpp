// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. 

//Brute force approach 1, TC = O(NlogN), SC = O(1)
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   sort(arr, arr+n);
}


//Brute force approach 2, TC = O(N) + O(N), SC = O(1)
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int one = 0;
   int two = 0;
   int zero = 0;
   for(int i=0; i<n; i++){
      if(arr[i]==0) zero++;
      else if(arr[i]==1) one++;
      else two++;
   }

   int i=0;
   while(zero--){
      arr[i++] = 0;
   }
   while(one--){
      arr[i++] = 1;
   }
   while(two--){
      arr[i++] = 2;
   }
}

//Optimised approach, TC=O(N), SC = O(1)
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low = 0;
   int mid = 0;
   int high = n-1;
   while(mid<=high){
      if(arr[mid]==0){
         swap(arr[low], arr[mid]);
         low++;
         mid++;
      }
      else if(arr[mid]==1){
         mid++;
      }
      else{
         swap(arr[high], arr[mid]);
         high--;
         
      }
   }
}
