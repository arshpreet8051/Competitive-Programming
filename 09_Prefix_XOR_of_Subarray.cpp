#include<bits/stdc++.h>
using namespace std;


// Problem link : https://leetcode.com/problems/xor-queries-of-a-subarray/



class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        // use precomputation technique, instead of using prefix sum use prefix xor


        /* Property used: The property you're referring to in the equation 
        prefix_xor[R] ^ prefix_xor[L-1] =  14 (XOR of all elements) ^ 6 (XOR of elements before 2) = 8 
        (XOR of elements from 2 to 3) is called         
        Cancellation of Identical Elements with XOR.
        */

        /*

            step - 1 
                     : Make a prefix xor array where arr[i] - stores xor from 0 to i th index
                     : for given queries - 
                                           CASE - 1 : if L <= 0  ->  return arr[R]
                                           CASE - 2 : if L > 0   ->  return arr[L-1] ^ arr[R]
        */

            for(int i = 1;i<arr.size();i++){
                arr[i] = arr[i] ^ arr[i-1];
            }

        vector<int> ans;

        for(auto it:queries){
            
            int left = it[0];
            int right = it[1];

            if(left<=0)ans.push_back(arr[right]);
            else{
                ans.push_back(arr[left-1] ^ arr[right]);
            }

        }
        return ans;

    }
};