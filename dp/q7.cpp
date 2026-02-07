#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mini(int a , int b , int c){
        if(a < b){
            if(a < c){
                return a;
            }else{
                return c;
            }
        }
        
        if(b < c){
            return b;
        }
        return c;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m , vector<int>(n , -1));
        for(int i = 0 ; i < n ; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                //just from top
                int top = INT_MAX;
                int tr = INT_MAX;
                int tl = INT_MAX;

                top = matrix[i][j] + dp[i-1][j];
                //top and right
                if(j + 1 < n){
                    tr = matrix[i][j] + dp[i-1][j+1];
                }
                //top and left
                if(j-1>=0){
                    tl = matrix[i][j] + dp[i-1][j-1];
                }

                dp[i][j] = mini(top , tr , tl);
            }
        }

        int min_path = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            min_path = min(min_path , dp[m-1][i]);
        }

        return min_path;
    }