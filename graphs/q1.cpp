#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//counting number of islands


void bfs(vector<vector<int>>& visited , int row , int col , vector<vector<char>>& grid , int rows , int cols){
        visited[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row , col});

        vector<int> new_row = {0 , 1 , 0 , -1};
        vector<int> new_col = {1 , 0 , -1 , 0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + new_row[i];
                int nc = c + new_col[i];

                if(nr >=0 && nr < rows && nc >=0 && nc < cols && grid[nr][nc] == '1' && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr , nc});
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        vector<vector<int>> visited(rows , vector<int>(cols , 0));

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(visited , i , j , grid , rows , cols);
                    count++;
                }
            }
        }

        return count;
    }