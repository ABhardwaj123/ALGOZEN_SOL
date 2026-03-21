#include<iostream>
#include<vector>
#include<string>
using namespace std;


int minDistance(string word1, string word2){
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

    for(int i = 0 ; i <= n ; i++) dp[i][0] = i;
        for(int j = 0 ; j <= m ; j++) dp[0][j] = j;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){

                if(word1[i-1] == word2[j-1]){ // character match , no operations needed
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]));
                }
            }
        }

        return dp[n][m];
}


//recursive + memoization approach
// int countPossibilites(int i , int j , string& s1 , string& s2 , vector<vector<int>>& dp){
//     //base case
//     if(i < 0) return j+1;
//     if(j < 0) return i+1;

//     if(dp[i][j] != -1) return dp[i][j];

//     int insert = 0;
//     int del = 0;
//     int replace = 0;

//     if(s1[i] == s2[j]){
//         return countPossibilites(i-1 , j-1 , s1 , s2 , dp);
//     }else{
//         insert = 1 + countPossibilites(i , j-1 , s1 , s2 , dp);
//         del = 1 + countPossibilites(i-1 , j , s1 , s2 , dp);
//         replace = 1 + countPossibilites(i-1 , j-1 , s1 , s2 , dp);
//     }

//     return dp[i][j] = min(del , min(insert , replace));
// }