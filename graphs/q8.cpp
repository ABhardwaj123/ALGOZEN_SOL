#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int> , int>> q; //{row , col} , time
        int rows = grid.size();
        int cols = grid[0].size();

        int time = 0;
        vector<vector<int>> visited(rows , vector<int>(cols , 0));

        int oranges = 0;
        int rotten = 0;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2;
                    oranges++;
                    rotten++;
                }else if(grid[i][j] == 1){
                    oranges++;
                }
            }
        }

        vector<int> new_row = {0 , 1 , 0 , -1};
        vector<int> new_col = {1 , 0 , -1 , 0};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(t , time);

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + new_row[i];
                int nc = c + new_col[i];

                if(nr >= 0 && nr < rows && nc >=0 && nc < cols && visited[nr][nc] == 0 && grid[nr][nc] == 1){
                    q.push({{nr , nc} , t+1});
                    visited[nr][nc] = 1;
                    rotten++;
                }

            }
        }

        if(oranges != rotten) return -1;

        return time;

    }