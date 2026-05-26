#include<iostream>
#include<vector>
using namespace std;

    int tryingAllCombos(int i , int j , int m , int n , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i >=m || j >= n){
            return 1e9;
        }

        if(i == m -1 && j == n - 1){
            return grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        //move down
        int dSum = grid[i][j] + tryingAllCombos(i + 1 , j , m , n , grid , dp);
        //move right
        int rSum = grid[i][j] + tryingAllCombos(i , j + 1 , m , n , grid , dp);

        return dp[i][j] = min(dSum , rSum);
    }

    int minPathSum(vector<vector<int>>& grid) {
        // int rows = grid.size();
        // int cols = grid[0].size();

        // vector<vector<int>> dp(rows , vector<int>(cols , -1));

        // for(int i = 0 ; i < rows ; i++){
        //     for(int j= 0 ; j < cols ; j++){
        //         if(i == 0 && j ==0){
        //             dp[0][0] = grid[0][0];
        //         }else{
        //             int up = grid[i][j];
        //             int left = grid[i][j];

        //             if(i - 1 >= 0){
        //                 up += dp[i-1][j];
        //             }else{
        //                 up += 1e9; // adding a maximum value so that it has a big value , not a possible path
        //             }

        //             if(j - 1 >=0){
        //                 left += dp[i][j-1];
        //             }else{
        //                 left += 1e9;
        //             }

        //             dp[i][j] = min(up , left);
        //         }
        //     }
        // }

        // return dp[rows-1][cols-1];

        int r = 0;
        int c = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m , vector<int>(n , -1));

        return tryingAllCombos(0 , 0 , m , n , grid , dp);
    }