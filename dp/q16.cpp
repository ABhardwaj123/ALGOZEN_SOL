#include<iostream>
#include<vector>
using namespace std;

    int tryingCombos(int idx , vector<int>& prices , int canBuy , vector<vector<int>>& dp){
        if(idx >= prices.size()){
            return 0;
        }

        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        
        int x = 0;
        int y = 0;

        if(canBuy){
            x = -prices[idx] + tryingCombos(idx + 1 , prices , 0 , dp);
            y = tryingCombos(idx + 1 , prices , 1 , dp);
        }else{
            x = prices[idx] + tryingCombos(idx + 2 , prices , 1 , dp);
            y = tryingCombos(idx + 1 , prices , 0 , dp);
        }

        return dp[idx][canBuy] = max(x , y);
    }

    int maxProfit(vector<int>& prices) {
        int idx = 0;
        int canBuy = 1;

        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));

        return tryingCombos(idx , prices , canBuy , dp);
    }