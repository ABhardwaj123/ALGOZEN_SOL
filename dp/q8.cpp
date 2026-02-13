#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    //tabulation
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size() , vector<int>(amount + 1 , 0));

        for(int i = 0 ; i <= amount ; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }else{
                dp[0][i] = 1e9;
            }
        }


        for(int i = 1 ; i < coins.size() ; i++){
            for(int amt = 0 ; amt <= amount ; amt++){
                int notTake = dp[i-1][amt];
                int take = INT_MAX;

                if(coins[i] <= amt){
                    take = 1 + dp[i][amt - coins[i]];
                }

                dp[i][amt] = min(take , notTake);
            }
        }

        int numCoins = dp[coins.size()-1][amount];

        if(numCoins == 1e9) return -1;
        return numCoins;
    }
};

//memoization
// int countCoins(int idx , int amount , vector<int>& coins , vector<vector<int>>& dp){
//         //base cases
//         if(idx == 0){
//             if(amount % coins[0] == 0){
//                 return amount / coins[0];
//             }else{
//                 return 1e9;
//             }
//         }

//         if(dp[idx][amount] != -1) return dp[idx][amount];

//         //actual recursion
//         int notTake = countCoins(idx - 1 , amount , coins , dp);
//         int take = INT_MAX;
//         if(coins[idx] <= amount){
//             take = 1 + countCoins(idx , amount - coins[idx] , coins , dp);
//         }

//         return dp[idx][amount] = min(notTake , take);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size() , vector<int>(amount + 1 , -1));
//         int numOfCoins =  countCoins(coins.size() - 1 , amount , coins , dp);

//         return numOfCoins == 1e9 ? -1 : numOfCoins;
//     }