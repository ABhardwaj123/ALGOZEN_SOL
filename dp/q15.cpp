#include<iostream>
#include<vector>
using namespace std;

    int findingProfit(int idx , vector<int>& prices , int buy_or_not , int transactions , vector<vector<vector<int>>>& dp){
        //base cases
        if(transactions == 0) return 0;
        if(idx == prices.size()) return 0;

        if(dp[idx][buy_or_not][transactions] != -1) return dp[idx][buy_or_not][transactions];

        int buy=0;
        int notBuy=0;

        if(buy_or_not == 1){ // you can buy
            //either you buy the current stock || you still wait to 
            int buy1 = findingProfit(idx + 1 , prices , 0 , transactions , dp) - prices[idx]; 
            int buy2 = findingProfit(idx + 1 , prices , 1 , transactions , dp);
            buy = max(buy1 , buy2);

        }else{//you cant buy
            //when you cant buy , it means you already have a stock
            //either you sell the current one || you still wait
            int notBuy1 = prices[idx] + findingProfit(idx + 1 , prices , 1 , transactions - 1 , dp);
            int notBuy2 = findingProfit(idx + 1 , prices , 0 , transactions , dp);
            notBuy = max(notBuy1 , notBuy2);
        }

        return dp[idx][buy_or_not][transactions] = max(buy , notBuy);
    }
    int maxProfit(vector<int>& prices) {
        int idx = 0;
        int buy_or_not = 1;
        int transactions = 2;
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3 , -1)));

        return findingProfit(idx , prices , buy_or_not , transactions , dp);

    }