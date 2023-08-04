// http://rb.gy/rzigm

#include <bits/stdc++.h>

void solve(vector<vector<int>> &mat,int n, int i, int j, string s, vector<string> &ans){
    if(i == n-1 && j == n-1){
        ans.push_back(s);
        return;
    }

    if(i>=n || j>=n || i<0 || j<0 || mat[i][j] == 0) return;

    mat[i][j] = 0;
    
    solve(mat, n, i+1, j, s+"D", ans);
    solve(mat, n, i, j+1, s+"R", ans);
    solve(mat, n, i-1, j, s+"U", ans);
    solve(mat, n, i, j-1, s+"L", ans);
    

    mat[i][j] = 1;
    return ;


}

vector<string> ratMaze(vector<vector<int>> &mat) {
    vector<string> ans;
    int n = mat.size();
    if(mat[0][0] == 0 || mat[n-1][n-1] == 0) return ans;
    string s = "";
    solve(mat,n, 0, 0, s, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
