#include<iostream>
#include<vector>
using namespace std;

    void dfs(int row , int col , vector<vector<char>>& board , vector<vector<int>>& visited){
        visited[row][col] = 1;
        int rows = board.size();
        int cols = board[0].size();

        //check for 4 directionality
        vector<int> new_row = {0 , 1 , 0 , -1};
        vector<int> new_col = {1 , 0 , -1 , 0};

        for(int i = 0 ; i < 4 ; i++){
            int nr = row + new_row[i];
            int nc = col + new_col[i];

            if(nr >=0 && nr < rows && nc >=0 && nc < cols && !visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr , nc , board , visited);
            }
        }


    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows , vector<int>(cols , 0));

        //now we start with the boundary traversal
        for(int i = 0 ; i < cols ; i++){
            //first row
            if(!visited[0][i] && board[0][i] == 'O'){
                dfs(0 , i , board , visited);
            }

            //last row
            if(!visited[rows - 1][i] && board[rows-1][i] == 'O'){
                dfs(rows - 1, i , board , visited);
            }
        }

        //now first col and last col
        for(int i = 0 ; i < rows ; i++){
            //first col
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i , 0 , board , visited);
            }

            //last col
            if(!visited[i][cols - 1] && board[i][cols - 1] == 'O'){
                dfs(i , cols - 1 , board , visited);
            }
        }

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){

                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }