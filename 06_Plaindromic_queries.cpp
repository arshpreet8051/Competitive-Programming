/*
    Question:
             - given testcases - t and queries - q
             - given string s 
             - given range l and r
             - for each query state that if the substring in the range l and r is palindrom or not

*/

#include<bits/stdc++.h>
using namespace std;
 

// int main()
// {

// // Approach 1 -> Brute Force

// /*
//     Simple approach using hashing
// */

// int t;
// cin>>t;

// while(t--){

//     string s;
//     cin>>s;

//     int q;
//     cin>>q;
    
//     while(q--){

//         int l,r;
//         cin>>l>>r;
//         vector<int> hash(26);

//         // Note 'l' and 'r' are inclusive but indexing in string is zero based
//         l--;
//         r--;
//         for(int i = l;i<=r;i++){
//             hash[s[i]-'a']++;
//         }

//         // Logic -> for a plaindrome only one char can be with odd no of occurences - rest shou;d be even
//         int odd_occurences = 0;

//         for(int i = 0;i<26;i++){
//             if(hash[i]%2!=0)odd_occurences++;
//         }

//         if(odd_occurences>1)cout<<"NO"<<endl;
//         else cout<<"Yes"<<endl;}
// }

// return 0;
// }

/*

Time Complexity Analysis

t ~ 10 ^ 5
n ~ 10 ^ 5
q ~ 10

T.C. = O( t * (q + n (n)))
     = O(t*q*n) ~ O(t*n) ~ 10^10

*/


int main(){

    int t;
    cin>>t;

    while(t--){

        int q,n;
        cin>>q>>n;

        string s;
        cin>>s;

        // 2-D array to store prefix sums of each integer
        vector<vector<int>>hash(26,vector<int>(n));

        for(int i = 0;i<n;i++){
            hash[s[i]-'a'][i]++;
        }

        // now compute prefis sum
        for(int i = 0;i<26;i++){
            for(int j = 1;j<n;j++){
                hash[i][j] += hash[i][j-1];
            }
        }
        while(q--){

            int l,r;
            cin>>l>>r;
            l--;
            r--;

            int odd_occurence = 0;

            for(int i = 0;i<26;i++){
                int char_count = hash[i][r] - hash[i][l-1];
                if(char_count%2!=0)odd_occurence++;
            }

            if(odd_occurence>1)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;

        }

    }


}
// T.C. = O(T*26) = 10^5