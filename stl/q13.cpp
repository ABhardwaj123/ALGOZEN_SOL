#include<iostream>
#include<vector>
#include<string>
using namespace std;

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        
        for(int i = 0 ; i < n/2; i++){
            
            for(int j = i ; j < n - i - 1 ; j++){
                
                int r1 = i;
                int c1 = j;
                int v1 = matrix[r1][c1];

                int r2 = j;
                int c2 = n - 1 - r1;
                int v2 = matrix[r2][c2];

                int r3 = c2;
                int c3 = n - 1 - r2;
                int v3 = matrix[r3][c3];

                int r4 = c3;
                int c4 = n - 1 - r3;
                int v4 = matrix[r4][c4];

                matrix[r2][c2] = v1;
                matrix[r3][c3] = v2;
                matrix[r4][c4] = v3;
                matrix[r1][c1] = v4;
            }
        }
    }