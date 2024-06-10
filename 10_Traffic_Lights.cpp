// problem link -> https://practice.geeksforgeeks.org/contest/gfg-weekly-158-rated-contest/problems

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string trafficLights(int n, int q, vector<vector<int>> &queries)
    {

        /*
            - construct an array for prefix computation
            - mark start eith +1
            - mark end with -1
            - compute prefix sum
            - arr value mod 3  - '0' Red - '1' Yellow - '2' Green
            */

        // intialize with all reds
        string lights(n, 'R');

        // maintain a array to start and end index to be changed
        vector<int> delta(n);

        for (auto it : queries)
        {

            // convert from '1' based to '0' based indexes
            int start = it[0] - 1;
            int end = it[1] - 1;

            delta[start] += 1;

            if (end + 1 < n)
                delta[end + 1] -= 1;
        }

        // now compute prefix sum
        for (int i = 1; i < n; i++)
        {
            delta[i] = delta[i] + delta[i - 1];
        }

        // now toggle lights
        for (int i = 0; i < n; i++)
        {

            // case - 1
            if (delta[i] % 3 == 0)
            {
                lights[i] = 'R';
            }
            else if (delta[i] % 3 == 1)
            {
                lights[i] = 'Y';
            }
            else
            {
                lights[i] = 'G';
            }
        }

        return lights;
    }
};