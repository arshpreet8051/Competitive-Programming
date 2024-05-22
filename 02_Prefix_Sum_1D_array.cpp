#include<bits/stdc++.h>
using namespace std;

/*

    Question: 
              Given 'Q' queries and 'N' sized array
              with each query given 'l' and 'r'
              find sum of elements from 'l' to 'r' in arary

*/


// Naive approach - O(n^2)

int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    // quries - q
    int q;
    cin>>q;

    while(q--){

        int l,r;
        cin>>l>>r;

        int sum = 0;

        for(int i = l;i<=r;i++){
            sum += arr[i];
        }

        cout<<sum<<endl;
    }
    return 0;
}

/*

    queries               = O(q)
    find sum (worst case) = O(n)

    q ~ 10^5
    n ~ 10^5

    T.C. = O(q) * O(n) ~ O(n^2)

*/

//--------------------------------------------------------------------------------------------------

// Prefix sum - O(n)

int main2(){

    int n;
    cin>>n;
    int arr[n];

    int prefix_sum[n];

    cin>>arr[0];
    prefix_sum[0] = arr[0];  // first element will have prefix sum as itself

    for(int i = 1;i<n;i++){
        cin>>arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    int q;
    cin>>q;

    while(q--){

        int l,r;
        cin>>l>>r;

        int ans = prefix_sum[r] - prefix_sum[l-1];

        cout<<ans<<endl;
    }
}

/*

    arr input               = O(n)
    queries                 = O(q)
    prefix sum computation  = O(1)

    as nested loop is removed in prefix sum logic so,

    T.C. = O(n) + O(q) + O(1)

    worst case = O(n)

*/