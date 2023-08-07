// https://www.codingninjas.com/studio/problems/1082553?topList=striver-sde-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h>

int find_parent(int u, vector<int> &parent) {
	if(parent[u] == u){
		return u;
	}
	return parent[u] = find_parent(parent[u], parent);
}

void union_set(int u, int v, vector<int>&parent, vector<int> &rank){
	u = find_parent(u, parent);
	v = find_parent(v, parent);
	if(rank[u]<rank[v]){
		parent[u] = v;
	}
	else if(rank[v]<rank[u]){
		parent[v] = u;
	}
	else{
		parent[v] = u;
		rank[u]++;
	}
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<int> rank(n+1);
	vector<int> parent(n+1);
	for(int i=1; i<=n; i++){
		parent[i] = i;
		rank[i] = 0;
	}

	int ans = 0;

	sort(edges.begin(),edges.end(),[&](vector<int> &a,vector<int> &b){
		return a[2]<b[2];
	});

	for(int i=0; i<edges.size(); i++){
		int u = find_parent(edges[i][0], parent);
		int v = find_parent(edges[i][1], parent);
		int w = edges[i][2];

		if(u!=v){
			ans+=w;
			union_set(u, v, parent, rank);
		}
	}

	return ans;

}
