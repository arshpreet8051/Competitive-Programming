#include<bits/stdc++.h>
using namespace std;

/*

Question:
         - given an initial array of 0's
         - given a,b and k
         - from a to b add k to array elements
         - after all the queries return max element in array
*/

// As array size can go too large we cannot declare it indisde main

// const int N = 1e9 + 7;
// long long int arr[N];

// int main()
// {

//     int n,m;
//     cin>>n>>m;

//     // m -> no of queries

//     while(m--){

//         int a,b,k;
//         cin>>a>>b>>k;

//         for(int i = a;i<=b;i++){
//             arr[i] += k;
//         }

//     }

//     int ans = -1;
//     for(int i = 0;i<=n;i++){
//         if(arr[i]>ans)ans = arr[i];
//     }

//     cout<<ans<<endl;

// return 0;
// }


// ---------------------------------------------------------------------

// Approach - 1

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
    
    vector<long int> v(n+10,0);
    
    for(auto it : queries){
        int a = it[0];
        int b = it[1];
        int c = it[2];
        
        for(int i = a;i<=b;i++){
            v[i] += c;
        }
    }
    
    long int ans = -1;
    for(int i = 0;i<=n;i++){
        if(v[i] > ans) ans = v[i];
    }
    
    return ans;
}
/*

Time complexity

outer loop + inner loop = O(m * n)
loop for max ele        = O(n)

T.C. = O( m * n + n)
T.C. = O(m*n)

m ~ 10^7
n ~ 10^5

T.C. = 10^12

*/

// --------------------------------------------------------------

// Approach - 2

/*

    Algo 
         - given a,b and c
         - they want us to do add 'c' to all elements from 'a' to 'b'
   *GAME - but we will do - arr[a] = arr[a] + c
                          - arr[b+1] = arr[b+1] + c
         - Now we will calculate prefix sum
         - we will attain array after adding 'c' for all queries in O(n)
         - Noe calculate max element
*/

long arrayManipulation(int n, vector<vector<int>> queries) {
    
    vector<long int> v(n+10,0);
    
    for(auto it : queries){
        int a = it[0];
        int b = it[1];
        int c = it[2];
        
        v[a] += c;
        v[b+1] -= c;
    }
    
    long int ans = -1;
    for(int i = 1;i<=n;i++){
        v[i] = v[i] + v[i-1];
    }
    
    for(int i = 0;i<=n;i++){
        if(v[i]>ans)ans = v[i];
    }
    
    return ans;
}

/*

Time Complexity analysis:

queries loop  = O(m) 
prefix loop = O(n)
max calculation loop = O(n)

T.C. = O(m + n + n) ~ O(m)

m ~ 10^7 -> T.C. = 10^7


*/