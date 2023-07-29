// https://rb.gy/i3c0m

//Using stack and dfs
#include <bits/stdc++.h> 

void solve(unordered_map<int, list<int>> adjlist, map<int, bool> &visited, int curr, stack<int> &s ){
    visited[curr] = true;
    for(auto i : adjlist[curr]){
        if(!visited[i]){
            solve(adjlist, visited, i, s);
        }
    }
    s.push(curr);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;

    //Finding adjacency list
    unordered_map<int, list<int>> adjlist;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
    }

    map<int, bool> visited;
    stack<int> s;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            solve(adjlist, visited, i, s);
        }
    }
    

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

    
    return ans;
}

//Kahn's algorithm
#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;


    //Finding adjacency list
    unordered_map<int, list<int>> adjlist;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
    }

    //Finding indegree
    vector<int> indegree(v);
    for(auto i : adjlist){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    //Find the node with 0 indegree and push it in the queue
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //Do BFS
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //Insert the element in the answer array
        ans.push_back(front);

        for(auto i: adjlist[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }

    
    return ans;
}
