//Problem link - https://shorturl.at/DIOP7


//Problem statement - Problem Statement: Given an array of integers arr[] and an integer target.
//1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
//2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}


//Brute force approach, TC = O(N^2), SC = O(1)
#include <bits/stdc++.h>

string read(int n, vector<int> book, int target)
{
    for(int i=0; i<n; i++){
        int b = target-book[i];
        for(int j=0; j<n; j++){
            if(book[j]==b){
                return "YES";
            }
        }
    }
    return "NO";
    
    
}

//Using hashmaps, TC=O(NLOGN), SC = O(N)
#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        if(m.find(target-book[i]) != m.end()){
            return "YES";
        }
        else{
            m[book[i]] = i;
        }
    }
    return "NO";
}

//Using two pointers, TC = O(NLOGN), SC = O(1)
#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{

    sort(book.begin(), book.end());
    int left = 0;
    int right = n-1;
    while(left < right){
        if(book[left]+book[right] == target){
            return "YES";
        }
        else if(book[left]+book[right] < target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}

