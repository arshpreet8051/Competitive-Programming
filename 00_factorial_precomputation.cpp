#include <bits/stdc++.h>
using namespace std;

// Old method

int main()
{

    // testcases - t
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // as fact of 0 and 1 is 1
        int ans = 1;

        for (int i = n; i >= 2; i--)
        {
            ans = ans * i;
        }

        return ans;
    }

        /* 
        if t <= 10^5
        and n <= 10^5
        T.C. = O(t*n) = 10^10 - not possible in 1 sec - should be less than 10^7
        */ 
}


// Precomputation

int main2(){

    // N - max possible value of n
    int N = 1e5 + 1;
    int fact[N];

    fact[0] = fact[1] = 1;

    for(int i = 2;i<=N;i++){
        fact[i] = i * fact[i-1];
    }

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        return fact[n];
    }

    /*
    
        factorial loop = O(N) ~ N = 10^5
        testcase loop = O(T)  ~ T = 10^5

        T.C. = O(N) + O(T) ~ O(T) ~  10^5
    */
}