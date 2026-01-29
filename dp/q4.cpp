#include<iostream>
#include<vector>
using namespace std;

//number of unique paths using DP
//TC : O(n * m)
//SC : O(n * m)

//tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        dp[0][0] = 1;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if((i == 0 && j == 0) || (obstacleGrid[i][j] == 1)){ // already set base case , obv to skip obstacles
                    continue;
                }

                int up = 0;
                int left=0;

                if(i-1>=0 && dp[i-1][j] != -1) up = dp[i-1][j]; // this upward movement is counter for actual downward movement
                if(j-1>=0 && dp[i][j-1] != -1) left = dp[i][j-1]; // this left movement is counter for actual right movement

                dp[i][j] = up+left;//summing up all possible unique ways
            }
        }

        return dp[rows-1][cols-1] == -1 ? 0 : dp[rows-1][cols-1];
    }