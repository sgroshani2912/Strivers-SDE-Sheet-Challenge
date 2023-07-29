// http://rb.gy/u429z

//Using BFS
#include <bits/stdc++.h>

bool solve(map<int, list<int>> adjlist, vector<int> &color, int curr ){
	//Queue due to BFS approach
	queue<int> q;
	q.push(curr);
	color[curr] = 0;

	while(!q.empty()){
		auto front = q.front();
		q.pop();

		for(auto i: adjlist[front]){
			if(color[i]==-1){
				q.push(i);
				color[i] = !color[front];
			}
			else if(color[i]==color[front]){
				return false;
			}
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	map<int, list<int>> adjlist;
	for(int i=0;i<edges.size();i++){
		for(int j=0;j<edges[0].size();j++){
			if(edges[i][j]==1){
				adjlist[i].push_back(j);
				adjlist[j].push_back(i);
			}
		}
	}

	int n = edges.size();

	vector<int> color(n, -1);

	for(int i=0; i<n; i++){
		if(color[i]==-1){
			bool ans = solve(adjlist, color, i);
			if(!ans) return false;
		}
	}
	return true;

}

//Using DFS
#include <bits/stdc++.h>

bool solve(map<int, list<int>> adjlist, vector<int> &color, int curr , int c){
	color[curr] = c;
	
	for(auto i: adjlist[curr]){
		if(color[i]==-1){
			if(solve(adjlist, color, i, !c) == false) return false;
		}
		else if(color[i] == color[curr]) return false;
	}

	return true;
	
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	map<int, list<int>> adjlist;
	for(int i=0;i<edges.size();i++){
		for(int j=0;j<edges[0].size();j++){
			if(edges[i][j]==1){
				adjlist[i].push_back(j);
				adjlist[j].push_back(i);
			}
		}
	}

	int n = edges.size();

	vector<int> color(n, -1);

	for(int i=0; i<n; i++){
		if(color[i]==-1){
			bool ans = solve(adjlist, color, i, 0);
			if(!ans) return false;
		}
	}
	return true;

}
