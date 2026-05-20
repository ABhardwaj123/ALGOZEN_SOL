#include<iostream>
#include<vector>
using namespace std;

//advanced version of buy and sell stock I
//in this you can buy and sell multiple stocks but can hold one at a time

int tryingCombos(int idx , vector<int>& prices , int canBuy , vector<vector<int>>& dp){
        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];

        int x = 0;
        int y = 0;

        if(canBuy){//can buy -> can buy now or wait
            //can buy now
            x = -prices[idx] + tryingCombos(idx + 1 , prices , 0 , dp);
            //wait  
            y = tryingCombos(idx + 1 , prices , canBuy , dp);

        }else{//cant buy -> can sell now or wait 
            //sell now
            x = prices[idx] + tryingCombos(idx + 1 , prices , 1 , dp);
            //wait
            y = tryingCombos(idx + 1 , prices , canBuy , dp);
        }

        return dp[idx][canBuy] = max(x , y);
    }

    int maxProfit(vector<int>& prices) {
        int canBuy = 1;
        int n = prices.size();

        vector<vector<int>> dp(n , vector<int>(2 , -1));

        return tryingCombos(0 , prices , canBuy , dp);
    }