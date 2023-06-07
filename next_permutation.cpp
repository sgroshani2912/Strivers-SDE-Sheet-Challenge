//Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
//If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

//solution, TC = 0(3*N), SC = O(1)
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    
    int brpt = -1;
    for(int i=0; i<n-1; i++){
        if(permutation[i] < permutation[i+1]){
            brpt = i;
        }
    }

    if(brpt == -1){
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    else{
        for(int i = n-1; i>brpt; i--){
            if(permutation[i]>permutation[brpt]){
                swap(permutation[i],permutation[brpt]);
                break;
            }
        }
        reverse(permutation.begin()+brpt+1, permutation.end());
        return permutation;
    }

    
}
