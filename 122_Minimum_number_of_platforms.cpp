// https://rb.gy/41f70

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int calculateMinPatforms(int at[], int dt[], int n) {

    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        pair<int, int> p = make_pair(at[i], dt[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(-1);
    int ans = 1;
    for(int i=0; i<n; i++){
        int curr = pq.top();
        if(curr<v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        else{
            ans++;
            pq.push(v[i].second);
        }
    }
    return ans;
}

//Solution without using extra space

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    int ans = 1;
    int plt = 1;
    int i = 1;
    int j = 0;
    
    while(i<n && j<n){
        if(at[i]>dt[j]){
            j++;
            plt--;
        }
        else{
            i++;
            plt++;
        }
        ans = max(ans, plt);
    }
    return ans;
    
}
    
