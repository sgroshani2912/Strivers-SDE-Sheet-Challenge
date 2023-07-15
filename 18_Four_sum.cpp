//Problem link - https://shorturl.at/ekMN4

//Brute force approach
#include <bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> st;

    int n = nums.size();
    for(int i= 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k= j+1; k<n; k++){
                for(int l=l+1; l<n; l++){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                        
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Better approach using one loop less and hashmap
#include <bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> st;

    int n = nums.size();
    for(int i= 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            set<int> hs;
            for(int k= j+1; k<n; k++){
                long long fourth = nums[i]+nums[j];
                fourth+=nums[k];
                if(hs.find(target-fourth) != hs.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],target-fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hs.insert(nums[k]);
            }
        }
    }

    //Pehle hum set banak usme unique elements daal rhe hai fir usko answer me store kar rhe hai
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

//Optimmised approach, using two loops and two pointer approach
#include <bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i= 0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j = i+1; j<n; j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;
            
            int k = j+1;
            int l = n-1;

            while(k<l){
                long long sum = nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                
                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(nums[k]==nums[k-1]) k++;
                    while(nums[l]==nums[l+1]) l--;
                }
                else if(sum<target){
                    k++;
                    while(nums[k]==nums[k-1]) k++;
                }
                else{
                    l--;
                    while(nums[l]==nums[l+1]) l--;
                }

            }
            

        }
    }

    return ans;

}
