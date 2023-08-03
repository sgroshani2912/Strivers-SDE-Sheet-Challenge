// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&leftPanelTab=1

//Brute force, TC = O(N), SC = O(N)
#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	int n = stack.size();
	vector<int> temp;
	while(!stack.empty()){
		temp.push_back(stack.top());
		stack.pop();
	}
	sort(temp.begin(), temp.end());

	for(int i=0; i<n; i++){
		stack.push(temp[i]);
	}
}

//Using Recursion, TC=O(N), SC = O(N)
#include <bits/stdc++.h> 

void insert_at_bottom(stack<int> &stack, int num){
	if(stack.empty() || stack.top()<=num){
		stack.push(num);
		return;
	}
	int n = stack.top();
	stack.pop();
	insert_at_bottom(stack, num);
	stack.push(n);
	return;
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	insert_at_bottom(stack, num);
	
}
