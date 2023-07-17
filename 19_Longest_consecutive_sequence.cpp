//  Problem link - https://www.codingninjas.com/studio/problems/759408?topList=striver-sde-sheet-problems&leftPanelTab=0

//Approach 1, TC = O(NLOGN), SC = O(1)
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int ans = 1;
    int count = 1;
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1] + 1){
            count++;
            ans = max(count, ans);
        }
        else if(arr[i]==arr[i-1]){
            continue;
        }
        else{
            ans = max(count, ans);
            count = 1;
        }
    }
    
    return ans;
}

//Optimal approach, TC = O(N), SC = O(1)
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }
    int ans = 1;
    
    for(int num: arr){
        //This is for finding sabse chhota wala element of consecutive subsequence
        if(!s.count(num-1)){
            int curr_num = num;
            int count = 1;
            while(s.count(curr_num+1)){
                count++;
                curr_num++;
            }
            ans = max(ans, count);
        }
        
    }
    return ans;
}
