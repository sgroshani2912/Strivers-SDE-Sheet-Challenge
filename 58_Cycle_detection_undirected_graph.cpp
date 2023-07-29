// http://rb.gy/snqz0

#include <bits/stdc++.h>


bool is_cycle_bfs(int source, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist){
    unordered_map<int, int> parent;
    queue<int> q;

    visited[source] = true;
    parent[source] = -1;
    q.push(source);
    while(! q.empty()){
        int curr = q.front();
        q.pop();

        for(auto i : adjlist[curr]){
            if(visited[i] == true && i!= parent[curr]){
                return true;
            }
            else if(!visited[i]){
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }
    return false;
}


bool is_cycle_dfs(int curr, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist){
    visited[curr] = true;

    for(auto i : adjlist[curr]){
        if(!visited[i]){
            bool ans = is_cycle_dfs(i, curr, visited, adjlist);
            if(ans){
                return ans;
            }
        }
        else if(i != parent){
            return true;
        }
    }
    return false;
    
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //First step is to find the adjacency list
    unordered_map<int, list<int>> adjlist;

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    //Seconf step is to call the function is_cycle

    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            bool ans = is_cycle_dfs(i,-1, visited, adjlist);
            if(ans){
                return "Yes";
            }
        }
    }

    return "No";
}
