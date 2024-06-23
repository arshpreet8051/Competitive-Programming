// Leetcode -> https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Transform nums: even -> 0, odd -> 1
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] % 2;
        }
        
        // Create prefix sum array
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        
        unordered_map<int, int> mp;
        int ans = 0;
        
        // Traverse prefix array
        for (int sum : prefix) {
            // Check if the prefix sum itself is equal to k
            if (sum == k) {
                ++ans;
            }
            // Check if there exists a prefix sum that gives sum-k
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            // Update the frequency of the current prefix sum
            ++mp[sum];
        }
        
        return ans;
    }
};
