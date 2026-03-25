#include<iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
        //fee for each buy and sell (total 2 transactions)
        int idx = 0;
        int buy = 1;
        int n = prices.size();

        //vector<vector<int>> dp(n + 1, vector<int>(2 , 0));
        vector<int> front(2 , 0);
        vector<int> current(2, 0);

        for(int idx = n -1 ; idx>=0 ; idx--){
            //i can buy the stock   
            //i buy now or i will buy next day
            current[1] = max(front[0] - prices[idx] , front[1]);
            //i cant buy the stock
            //now i sell the stock immediately or i hold it more
            current[0] = max(front[1] + prices[idx] - fee , front[0]);       

            front = current;    
        }

        return front[1];
    }

//recursion + memoization
//  int findProfit(int idx , int buy , int fee , vector<int>& prices , vector<vector<int>>& dp){
//         if(idx >= prices.size()) return 0;

//         if(dp[idx][buy] != -1) return dp[idx][buy];

//         int profit = 0;
//         if(buy){//i can buy the stock   
//             //i buy now or i will buy next day
//             profit = max(findProfit(idx + 1 , 0 , fee , prices , dp) - prices[idx] , 
//                 findProfit(idx + 1 , 1 , fee , prices , dp)
//             );
//         }else{//i cant buy the stock
//             //now i sell the stock immediately or i hold it more
//             profit = max(findProfit(idx + 1 , 1 , fee , prices , dp) + prices[idx] - fee ,
//                     findProfit(idx + 1 , 0 , fee , prices , dp)
//             );
//         }

//         return dp[idx][buy] = profit;
//     }