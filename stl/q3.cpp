#include<iostream>
#include<vector>
using namespace std;

//best time to buy and sell stock
//TC : O(N)
//SC : O(1)

int maxProfit(vector<int>& prices) {
        int price = prices[0];

        int max_profit = 0;
        
        for(int i = 1 ; i < prices.size() ; i++){
            if(price > prices[i]){
                price = prices[i];
            }
            else{
                max_profit = max(max_profit , prices[i] - price);
            }
        }

        return max_profit;
    }