//  http://rb.gy/cndm2

#include <bits/stdc++.h> 

void solve(string s, int idx, vector<string> &ans){
    if(idx == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i=idx; i<s.size(); i++){
        swap(s[idx], s[i]);
        solve(s, idx+1, ans);
        swap(s[idx], s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    solve(s, 0, ans);
    return ans;

}
