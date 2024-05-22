#include <bits/stdc++.h>
using namespace std;

/*
    Question:
                Given t - testcases and n sized array
                for each testcase given a number
                find the occurences of that number in the given array
*/

// OLD method
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int t;
    cin >> t;

    while (t--)
    {

        int x;
        cin>>x;

        int counter = 0;

        for(int i = 0;i<n;i++){
            if(arr[i]==x)counter++;
        }

        cout<<counter<<endl;
    }

    return 0;

    /*

        if t ~ 10^5
           n ~ 10^5

           T.C. = loop for arrat input + loop for testcases * (inside loop for finding occurences)
           T.C. = O(N) + O(T) * O(N)
           T.C. = O(N*T)
           worst case = T.C. = O(N^2) ~ 10^10  = not possible in one second
    */
}


// Precomputation

int main2(){

    int n;
    cin >> n;

    int arr[n];

    // precomputation array
    vector<int>occurences(n+1,0);

    for (int i = 0; i < n; i++)
    {
        int x; 
        cin>>x;
        arr[i] = x;
        occurences[x]++;
    }
    
    int t;
    cin >> t;

    while (t--)
    {

        int x;
        cin>>x;

        cout<<occurences[x]<<endl;
    }

    /*

        T.C. = array input loop + testcase loop
        T.C. = O(N) + O(T)

        if T ~ 10^5 and N ~ 10^5

        T.C. = O(N) = 10^5

    */
}