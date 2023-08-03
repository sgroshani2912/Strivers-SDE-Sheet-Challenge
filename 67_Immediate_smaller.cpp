// https://www.codingninjas.com/studio/problems/immediate-smaller-element-_1062597?leftPanelTab=1
void immediateSmaller(vector<int>& a)
{
	int n = a.size();
	for(int i=0; i<n-1; i++){
		if(a[i]>a[i+1]){
			a[i] = a[i+1];
		}
		else{
			a[i] = -1;
		}
	}
	a[n-1] = -1;
	return;
}

//Using stack, TC=O(N), SC = O(N)
#include <bits/stdc++.h>
void immediateSmaller(vector<int>& a)
{
	stack<int> st;
	int n = a.size();
	if(n<1) return; 
	for(int i=n-1; i>0; i--){
		st.push(a[i]);
	}
	int x = 0;
	while(x<n-1){
		if(st.top() < a[x]){
			a[x] = st.top();
			
		}
		else{
			a[x] = -1;
			
		}
		st.pop();
		x++;
	}
	
	a[n-1] = -1;
	return;
}

