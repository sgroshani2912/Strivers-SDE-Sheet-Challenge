// http://rb.gy/saw09
#include <bits/stdc++.h> 
bool comp(pair<int, int>a,pair<int, int>b)
{
    double x=(double)a.second/(double)a.first;
    double y=(double)b.second/(double)b.first;
    return x>y;
}
double maximumValue (vector<pair<int, int>>& x, int n, int w)
{
    double sum=0;
    sort(x.begin(),x.end(),comp);
    for(auto i:x) {
        if(w==0)break;
        if(i.first<=w){
            sum+=i.second;
            w=w-i.first;
        }
        else{
            sum+=((double)w/i.first)*i.second;
            w=0;
        }         }
    return sum;
}
