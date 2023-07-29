//http://rb.gy/2p4w8

//Kosaraju's Algorithm for strongly connected components 
#include <bits/stdc++.h>

//Topo sort
void topo(map<int, list<int>> adj, int curr, map<int, bool> &visited, stack<int> &s ){
    visited[curr] = true;
    for(auto i: adj[curr]){
        if(!visited[i]){
            topo(adj, i, visited, s);
        }
    }
    s.push(curr);
}

//dfs
void dfs(map<int, list<int>> adj, int curr, map<int, bool> &visited, vector<int> &temp ){
    visited[curr] = true;
    temp.push_back(curr);
    for(auto i: adj[curr]){
        if(!visited[i]){
            dfs(adj, i, visited, temp);
        }
    }
    
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    

    //Adjacency list
    map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //Topo stack
    stack<int> s;

    //Visited ds
    map<int, bool> visited;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            topo(adj, i, visited, s);
        }
    }

    //Transposing the graph
    map<int, list<int>> transpose;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        transpose[v].push_back(u);
    }

    //Restore the visited ds
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    //Do dfs according to topo sort and transpose of graph
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        vector<int> temp;
        if(!visited[curr]){
            dfs(transpose, curr, visited, temp);
        }
        ans.push_back(temp);

    }

    return ans;



}
