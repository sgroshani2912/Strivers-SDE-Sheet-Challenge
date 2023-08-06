//https://www.codingninjas.com/studio/problems/696444?topList=striver-sde-sheet-problems&leftPanelTab=3

#include <bits/stdc++.h>

string reverseString(string &str){
	string ans = "";
	stack<string> s;
	string temp = "";
	int i=0;
	while(i != str.size()){
		if(i>0 && str[i]!=' ' && str[i-1]== ' '){
			s.push(temp);
			temp = "";
			temp+=str[i];
		}
		else if(str[i] != ' '){
			temp += str[i];
		}
		i++;
	}
	s.push(temp);
	while(!s.empty()){
		ans+=s.top();
		s.pop();
		ans+= " ";
	}
	return ans;
}
