//Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

//Using frequency array, TC = O(NlogN), SC = O(N)
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    map<int, int> m;
    int n = arr.size();
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    vector<int> ans;
    for(auto i: m){
        if(i.second > n/3){
            ans.push_back(i.first);
        }
    }

    return ans;
 
}

//Optimal solution, TC = O(N), SC = O(1)
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1;
    int ele2;
    for(int i=0; i<n; i++){
        if(cnt1==0 && ele2 != arr[i]){
            cnt1++;
            ele1 = arr[i];
        }
        else if(cnt2==0 && ele1 != arr[i]){
            cnt2++;
            ele2 = arr[i];
        }
        else if(ele1 == arr[i]) cnt1++;
        else if(ele2 == arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==ele1){
            cnt1++;
        }
        if(arr[i]==ele2){
            cnt2++;
        }
    }

    vector<int> ans;
    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ans.push_back(ele1);
    if (cnt2 >= mini) ans.push_back(ele2);
    return ans;

}
