#include<iostream>
#include<vector>
#include<string>
using namespace std;

    bool dfs(int idx , string word , vector<vector<char>>& board , int r , int c){
        if(idx == word.size()) return true;

        if(r <0 || c <0 || r == board.size() || c == board[0].size() || board[r][c] != word[idx]){
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(idx + 1 , word , board , r , c+1) || dfs(idx + 1 , word , board , r+1 , c) ||
                        dfs(idx + 1 , word , board , r , c-1) || dfs(idx + 1 , word , board , r-1 , c);


        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(dfs(0 , word , board , i , j)){
                    return true;
                }
            }
        }

        return false;
    }