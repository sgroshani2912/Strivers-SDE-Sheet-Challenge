//Problem link - https://shorturl.at/acgHV

//Brute force approach, TC = O(N^2), SC = O(1)
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        int x = 0;
        for(int j=i; j<n; j++){
            x = x^a[j];
            if(x==b) ans++;
        }
    }
    return ans;
}

//Optimal approach, TC = O(N), SC = O(N)
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    unordered_map<int, int> m;
    int x = 0;
    m[x] = 1;
    int ans=0;
    for(int i=0; i<n; i++){
        x = x^a[i];
        int pre = x^b;
        if(m.find(pre) != m.end()){
            ans += m[pre]; 
            
        }
        m[x]++;
    }
    return ans;
}
