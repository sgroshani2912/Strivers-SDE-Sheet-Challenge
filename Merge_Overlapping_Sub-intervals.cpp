//Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

//Optimal solution, TC = 0(N)+O(NlogN), SC = O(N)
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    ans.push_back(intervals[0]);
    int n = intervals.size();

     
    for(int i=1; i<n; i++){
        //Case for merging the array
        if(intervals[i][0] <= end){
            int ans_last = ans.size()-1;
            ans[ans_last][0] = min(ans[ans_last][0], intervals[i][0]);
            ans[ans_last][1] = max(ans[ans_last][1], intervals[i][1]);
            start = ans[ans_last][0];
            end = ans[ans_last][1];

        }
        //Case for not merging the array, insert the interval as it is and update the start and end
        else{
            ans.push_back(intervals[i]);
            start = intervals[i][0];
            end = intervals[i][1];

        }
        
    }

    return ans;
}
