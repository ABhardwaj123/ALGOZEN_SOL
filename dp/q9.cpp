#include<iostream>
#include<vector>
using namespace std;

    class Solution {
public:
    bool tryingAllCombos(int idx , int sum , vector<int>& nums){

        if(sum == 0){
            return true;
        }

        if(idx == nums.size() -1) return nums[idx] == sum;

        bool take = tryingAllCombos(idx + 1 , sum - nums[idx] , nums);
        bool notTake = tryingAllCombos(idx + 1 , sum , nums);

        return take || notTake;
    }


    bool canPartition(vector<int>& nums) {
        int target_sum = 0;
        int n = nums.size();

        for(int x : nums){
            target_sum += x;
        }

        if(target_sum % 2 != 0) return false;

        vector<vector<bool>> dp(n, vector<bool>((target_sum / 2) + 1 , false));

        for(int i = 0 ; i < n ; i++){
            dp[i][0] = true;
        }   
             
        if(nums[0] <= target_sum / 2){
            dp[0][nums[0]] = 1;
        }

        for(int idx = 1 ; idx < n ; idx++){
            for(int sum = 1 ; sum <= (target_sum / 2) ; sum++){
                bool notTake = dp[idx-1][sum];
                bool take = false;
                if(nums[idx] <= sum){
                    take = dp[idx-1][sum - nums[idx]];
                }

                dp[idx][sum] = notTake||take;
            }
        }

        return dp[n-1][target_sum/2];
    }
};

//memoization
// bool calculatingCombinations(int idx , int sum , vector<int>& nums , vector<vector<int>>& dp){
//         if(sum == 0) return 1;

//         if(idx == 0){
//             return nums[idx] == sum;
//         }

//         if(dp[idx][sum] != -1) return dp[idx][sum];

//         bool notTake = calculatingCombinations(idx - 1 , sum , nums , dp);
//         bool take = false;
//         if(nums[idx] <= sum){
//             take = calculatingCombinations(idx - 1 , sum - nums[idx] , nums , dp);
//         }

//         return dp[idx][sum] =  notTake | take;
//     }

//     bool canPartition(vector<int>& nums) {
//         int total_sum = 0;
//         int n = nums.size()-1;

//         for(int x : nums){
//             total_sum += x;
//         }

//         if(total_sum % 2 != 0) return false;

//         vector<vector<int>> dp(n+1, vector<int>((total_sum / 2) + 1 , -1));

//         return calculatingCombinations(n , total_sum / 2 , nums , dp);
        
//     }