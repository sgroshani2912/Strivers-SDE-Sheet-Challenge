// https://www.codingninjas.com/studio/problems/1095633?topList=striver-sde-sheet-problems\

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //Adjaceny list
    unordered_map<int, list<pair<int, int>>> adjlist;
    for(int i=0; i<g.size(); i++){
        int x = g[i].first.first;
        int y = g[i].first.second;
        int z = g[i].second;

        adjlist[x].push_back(make_pair(y,z));
        adjlist[y].push_back(make_pair(x,z));
    }

    //Make 3 data structures key, mst, parent;
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    //Mark for source node
    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<=n; i++){
        int mini  = INT_MAX;
        int u;
        
        for(int i=1; i<=n; i++){
            if(mst[i]==false && key[i]<mini ){
                u = i;
                mini = key[i];
            }
        }
        mst[u] = true;

        for(auto i: adjlist[u]){
            int x = i.first;
            int d = i.second;
            if(mst[x]==false && d < key[x]){
                key[x] = d;
                parent[x] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++){
      result.push_back({{parent[i], i}, key[i]});
    }
    return result;


}
