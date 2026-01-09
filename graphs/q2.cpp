#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;

 //maximum area of island
 //Time Complexity :  O(n*m) {one for scanning all grid in the main function , one for bfs(worst case)}
 //Space Complexity :  O(n * m) {visited matrix and queue{worst case}}

void bfs(vector<vector<int>>& visited , int row , int col , vector<vector<int>>& grid , int rows , int cols , int& area){
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

                if(nr >=0 && nr < rows && nc >=0 && nc < cols && grid[nr][nc] == 1 && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr , nc});
                    area++;
                }
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int max_area = INT_MIN;
    
        vector<vector<int>> visited(rows , vector<int>(cols , 0));

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = 1;
                    bfs(visited , i , j , grid , rows , cols , area);
                    max_area = max(max_area , area);
                }
            }
        }

        return max_area == INT_MIN ? 0 : max_area;
    }