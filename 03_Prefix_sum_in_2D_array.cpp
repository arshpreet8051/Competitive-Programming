#include<bits/stdc++.h>
using namespace std;

/*

Given N x N matrix
Given points (a,b) and (c,d)

consider (a,b) as top left-most point and (c,d) as bottom right-most point
Find the sum between (a,b) and (c,d)

0 <= Q <= 10^5
0 <= N <= 10^5

*/


// Brute Force
int main()
{
    int n;
    cin>>n;
    int arr[n][n];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int q;
    cin>>q;

    while(q--){

        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int sum = 0;

        for(int row = a; row < c; row ++){
            for(int col = b; col < d; col++){
                sum += arr[row][col];
            }
        }

        return sum;
    }
    
return 0;
}

/*

    T.C. = input array  + queries loop * calculate sum
    T.C. = O(N^2) + O(Q) * O(N^2)
    T.C. = O(N^2) = 10^12
*/

//--------------------------------------------------------------------------------------------

// Prefis sum 2D array

const int N = 1e3;
long long arr[N][N];
long long pf[N][N];
int main2(){

    int n;
    cin>>n;

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){

            cin>>arr[i][j];

            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1]; // subtract the part that was added twice
        }
    }

    int q;
    cin>>q;

    while(q--){

        int a,b,c,d;
        cin>>a>>b>>c>>d;

        cout<<pf[c][d] - pf[a-1][c] - pf[b-1][d] + pf[a-1][b-1]; // adding the part that was deleted twice

    }
return 0;
}