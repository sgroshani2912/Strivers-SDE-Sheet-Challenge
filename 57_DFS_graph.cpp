// https://rb.gy/8jtw9

#include <bits/stdc++.h>

void dfs_traversal(vector<int> &comp, unordered_map<int, list<int>> &ajcList, map<int,bool> &visited, int curr  ){
    visited[curr] = true;
    comp.push_back(curr);

    for(auto i : ajcList[curr]){
        if(visited[i]==false){
            dfs_traversal(comp, ajcList, visited, i);
        }
    }

    return;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> ajcList;
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ajcList[u].push_back(v);
        ajcList[v].push_back(u);
    }

    map<int,bool> visited;
    stack<int> st;

    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        //Used for storing different components seperately
        vector<int> comp;
        if(visited[i]==false){
            dfs_traversal(comp, ajcList, visited, i); 
            ans.push_back(comp);
        }
       
    }

    return ans;
}
