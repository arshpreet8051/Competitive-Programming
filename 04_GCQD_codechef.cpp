#include<bits/stdc++.h>
using namespace std;

/*

Question:
            You are given an array A of integers of size N. 
            You will be given Q queries where each query is represented 
            by two integers L, R. 
            You have to find the gcd(Greatest Common Divisor) 
            of the array after excluding the part from 
            range L to Rinclusive

*/ 

//-------------------------------------------------------------------

/*

Constraint - 1
                T,N,Q ~ 100

Constraint - 2 
                T,N,Q ~ 10^5
*/

//--------------------------------------------------------------------

// Approach - 1 (Naive Approach)
int main1()
{

int t;
cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n+10];
        
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        while(q--){
            int l,r;
            cin>>l>>r;

            int gc = 0;

            for(int i = 1;i<=l-1;i++){
                gc = __gcd(gc,arr[i]);
            }

            for(int i = r+1;i<=n;i++){
                gc = __gcd(gc,arr[i]);
            }

            cout<<gc<<endl;
        }

    }
}

/*

T.C. =  T * (Q*N) 

based on constraint 1 - T*N*Q = 100^3 = 10^6

based on constraint 2 - T*N*Q = 10^5^3 = TLE
*/

//---------------------------------------------------------------

// Approach - 2 Precomputation

int main(){
    int t;
    cin>>t;

    while(t--){

        int n,q;
        cin>>n>>q;

        int arr[n+10];
        // to calculate gcd from left to right
        vector<int> forward(n+10);
        // to calculate gcd from right to left
        vector<int> backward(n+10);

        
        for(int i = 1;i<=n;i++){
            cin>>arr[i];
            
            if(i==1){
                forward[i] = arr[i];
            }
            else{
                forward[i] = __gcd(forward[i-1],arr[i]);
            }
        }

        // loop for backward gcd
        for(int i = n;i>=1;i--){
            if(i==n){
                backward[i] = arr[i];
            }
            else{
                backward[i] = __gcd(backward[i+1],arr[i]);
            }
        }


        while(q--){
            int l,r;

            cin>>l>>r;

            int gcd_l = forward[l-1];
            int gcd_r = backward[r+1];

            cout<<__gcd(gcd_l,gcd_r)<<endl;
        }
    }
}

// T.C. = T * (N + N) // given N < 10^6 = t.c = 10^6