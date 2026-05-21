#include<iostream>
#include<vector>
using namespace std;

    int tryingCombos(int idx , vector<int>& nums , vector<int>& dp){
        if(idx >= nums.size() - 1){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int minSteps = 1e9;
        int steps = nums[idx];

        for(int i = 1 ; i <= steps ; i++){
            minSteps = min(minSteps , 1 + tryingCombos(idx + i , nums , dp));
        }

        return dp[idx] = minSteps;
    }
    int jump(vector<int>& nums) {
        int idx = 0;
        vector<int> dp(nums.size() , -1); 

        return tryingCombos(idx , nums , dp);
    }