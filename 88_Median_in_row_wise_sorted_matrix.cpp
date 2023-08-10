// https://rb.gy/clcda

#include <bits/stdc++.h>

int solve(vector<int> &a, int mid){
    int l = 0;
    int h = a.size()-1;
    while(l<=h){
        int m = (l+h)>>1;
        if(a[m]<=mid) l = m+1;
        else h = m-1;
    }
    return l;
}


int median(vector<vector<int>> &matrix, int m, int n) {
    
    //Define search space 
    int low = 1;
    int high = 1e9;
    while(low<=high){
        int cnt = 0;
        int mid = (low+high)>>1;
        for(int i=0; i<m; i++){
            cnt+=solve(matrix[i], mid);
        }
        if(cnt<=(n*m)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}
