// https://www.codingninjas.com/studio/problems/920469?topList=striver-sde-sheet-problems

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // First create a adjacency list
    unordered_map<int, list<pair<int, int>>> adjlist;
    for(int i=0; i<edges; i++){
        int x = vec[i][0];
        int y = vec[i][1];
        int d = vec[i][2];

        adjlist[x].push_back(make_pair(y,d));
        adjlist[y].push_back(make_pair(x,d));
    }

    //Make a set data structure
    set<pair<int,int>> s;
    
    //Distance array;
    vector<int> ans(vertices);
    for(int i=0; i<vertices; i++){
        ans[i] = INT_MAX;
    }

    ans[source] = 0;
    s.insert(make_pair(0,source));
    while(!s.empty()){
        pair<int,int> top = *(s.begin());
        int top_d = top.first;
        int top_node = top.second;
        s.erase(s.begin());


        for(auto i: adjlist[top_node]){
            if(top_d + i.second < ans[i.first]){
                auto record = s.find(make_pair(ans[i.first],i.first));
                if(record != s.end()){
                    s.erase(record);
                }
                ans[i.first] = top_d + i.second;
                s.insert(make_pair(ans[i.first],i.first));
            }
            
        }
    }
    return ans;
}
