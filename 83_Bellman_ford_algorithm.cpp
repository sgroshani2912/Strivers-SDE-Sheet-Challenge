// https://www.codingninjas.com/studio/problems/2041977?topList=striver-sde-sheet-problems

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    //we will only require a distance vector

    vector<int> dis(n+1, 1e9);
    dis[src] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dis[u]!=1e9 && (dis[u] + w < dis[v])){
                dis[v] = dis[u]+w;
            }
        }
    }

    //Check for negative cycles
    int flag = 0;

    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dis[u]!=1e9 && ((dis[u] + w) < dis[v])){
            flag = 1;
        }
    }

    if(flag==0){
        return dis[dest];
    }
    else{
        return -1;
    }
}
