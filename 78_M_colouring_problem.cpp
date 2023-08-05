// http://rb.gy/7alpx

#include <bits/stdc++.h>

bool is_safe(int curr, int c, unordered_map<int, list<int>> adj, vector<int> &color ){

    for(auto i: adj[curr]){
        if(color[i] == c) return false;
    }

    return true;
}

bool solve(int m,int n, unordered_map<int, list<int>> adj, int curr, vector<int> &color ){
    if(curr==n){
        return true;
    }

    for(int i=0; i<m; i++){
        if(is_safe(curr, i, adj, color )){
            color[curr] = i;
            if(solve(m,n, adj, curr+1, color)==true) return true;
            color[curr] = -1;
        }
    }
    return false;


}

string graphColoring(vector<vector<int>> &mat, int m) {
    unordered_map<int, list<int>> adj;
    int n = mat.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }

    
    vector<int> color(n, -1);
    bool ans = solve( m,n, adj, 0, color);
    if(ans){
        return "YES";
    }
    return "NO";




}
