// Leetcode -> https://leetcode.com/problems/binary-subarrays-with-sum/


#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();

        vector<int> prefix(n,0);

        prefix[0] = nums[0];

        for(int i = 1;i<n;++i){

            prefix[i] = nums[i] + prefix[i-1];
        }


        int ans = 0;
        unordered_map<int,int>mp;

        for(auto sum : prefix){

            if(sum == goal)ans++;

            if(mp.find(sum-goal)!=mp.end()){
                ans += mp[sum-goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};