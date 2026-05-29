#include<iostream>
#include<vector>
#include <climits>
using namespace std;

    bool isPalindrome(string& s , int i , int j){

        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int findMinCuts(string s , int i , vector<int>& dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int min_cuts = INT_MAX;

        for(int j = i ; j < s.size() ; j++){

            if(isPalindrome(s , i , j)){
                int cuts = 1 + findMinCuts(s , j+1, dp);
                min_cuts = min(min_cuts , cuts);
            }
        }

        return dp[i] = min_cuts;
    }

    int minCut(string s){
        int i = 0;
        vector<int> dp(s.size() + 1 , -1);

        return findMinCuts(s , i, dp);
    }