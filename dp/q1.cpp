#include<iostream>
#include<vector>
using namespace std;

//climbing stairs
//TC : O(N)
//SC : O(N)

int climbStairs(int n) {
        
        //using memoization
        if(n == 1 || n == 2) return n;
        vector<int> memo(n+1 , 0);
        memo[1] = 1;
        memo[2] = 2;

        for(int i = 3 ; i <= n ; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }

        return memo[n];

    }