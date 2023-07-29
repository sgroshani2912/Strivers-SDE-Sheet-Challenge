// http://rb.gy/xscyf

#include <bits/stdc++.h> 

//First of all prepare a adjaceny list
void findAdjList(unordered_map<int, set<int>> &adjList,  vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs_traversal(unordered_map<int, bool > &visited, unordered_map<int, set<int>> &adjList, int source, vector<int> &ans ){
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for(auto i : adjList[curr]){
            if(visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int, bool > visited;
    unordered_map<int, set<int>> adjList;

    findAdjList(adjList, edges);
    
    //For loop for disconnected components
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs_traversal(visited, adjList, i, ans);
        }
    }

    return ans;
}
