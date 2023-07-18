//Problem link - https://shorturl.at/efAW5

//Optimised approach, TC = O(2*N), SC = O(N)
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    set<char> s;
    int n = input.size();
    int l = 0;
    int r = 0;
    int len = 0;
    while(r<n){
        char curr = input[r];
        if(s.find(curr)==s.end()){
            len = max(r-l+1, len);
            s.insert(curr);
            r++;
        }
        else{
            s.erase(input[l]);
            l++;
        }
    }

    return len;
}

//Optimal approach, using map, TC = O(N), SC = O(N)
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_map<char, int> m;
    int n = input.size();
    int l = 0;
    int r = 0;
    int len = 0;
    while(r<n){
        char curr = input[r];
        if(m.find(curr) != m.end()){
            l =  max(m[curr]+1, l);
        }
            
        m[curr] = r;
        len = max(len, r-l+1);
        r++;
    }

    return len;
}
