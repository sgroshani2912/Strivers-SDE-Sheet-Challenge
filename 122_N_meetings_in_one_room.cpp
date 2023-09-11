// http://rb.gy/wlbvc

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    //Using two for loop;
    int ans = 0;
    int n = start.size();
    int curr = -1;
    vector<pair<int, int>> m;
    for(int i=0; i<n; i++){
        pair<int, int> p = make_pair(start[i], end[i]);
        m.push_back(p);
    }
    sort(m.begin(), m.end(), cmp);
    for(auto i:m){
        if(i.first>curr){
            ans++;
            curr = i.second;
        }
    }
    return ans;

}
