// problem -> https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include<bits/stdc++.h>
using namespace std;


/*
    Iterative Approach: O(n^2)
*/
class Solution {
public:
    int winner(vector<int>&persons,int n,int k,int index,int person_left){

        if(person_left==1){
            for(int i = 0;i<n;i++){
                if(persons[i]==0)return i;
            }
        }

        int kill = (k-1)%person_left;

        while(kill--){

            index = (index + 1)%n;

            while(persons[index]==1){ // skip already killed person
                index = (index+1)%n;
            }

        }

        persons[index] = 1;

        // next alive person
        while(persons[index]==1){
            index = (index + 1) %n;
        }

        return winner(persons,n,k,index,person_left-1);
    }
    int findTheWinner(int n, int k) {
        
        vector<int>persons(n,0);
        return winner(persons,n,k,0,n)+1;
    }
};

//----------------------------------------------------------------------------------------

// Recursion -> O(n)


/*  
  Recursive Realation :
                        - T(n) = T(n-1) + k
                        - T(n-1) = T(n-2) + k
                        - ..............so on
*/ 
class Solution {
public:
    int winner(int n,int k){

        if(n==1)return 0;

        return (winner(n-1,k)+k)%n;

    }
    int findTheWinner(int n, int k) {
        
        return winner(n,k)+1;

    }
};