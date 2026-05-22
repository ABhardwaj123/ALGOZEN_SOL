#include<iostream>
#include<vector>
#include<string>
using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> posi;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    posi.push_back({i,j});
                }
            }
        }

        for(int i = 0 ; i < posi.size() ; i++){
            int r = posi[i].first;
            int c = posi[i].second;

            //first setting row 0
            for(int j = 0 ; j < cols ; j++){
                matrix[r][j] = 0;
            }
            //then setting col 0
            for(int j = 0 ; j < rows ; j++){
                matrix[j][c] = 0;
            }
        }
    }