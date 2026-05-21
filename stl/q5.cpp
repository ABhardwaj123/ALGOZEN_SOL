#include<iostream>
#include<vector>
using namespace std;

//each idx is number of jumps -> many possible ways -> recursion
//recursive solution got TLE -> DP

    bool tryingCombos(int idx , vector<int>& nums , vector<int>& dp){
        if(idx >= nums.size() -1){
            return true;
        }

        if(dp[idx] != -1) return dp[idx];

        int steps = nums[idx];
        bool possible = false;

        for(int i = 1 ; i<= steps ; i++){
            possible = tryingCombos(idx + i , nums , dp);

            if(possible) break;
        }

        return dp[idx] = possible;
    }

    bool canJump(vector<int>& nums) {
        int idx = 0;
        vector<int> dp(nums.size() , -1);

        return tryingCombos(idx , nums , dp);   
    }