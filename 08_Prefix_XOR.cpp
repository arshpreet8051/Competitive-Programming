#include<bits/stdc++.h>
using namespace std;
 
vector<int>Prefix_XOR(vector<int>&arr,int x,vector<vector<int>>&queries){

    for(auto it : queries){

        int left = it[0];
        int right = it[1];

        arr[left] ^= x;
        
        if(right+1<arr.size()){
            arr[right+1] ^= x;
        }
    }

    // now calculate prefix xor
    for(int i = 1;i<arr.size();i++){

        arr[i] = arr[i] ^ arr[i-1];
    }

    return arr;

}