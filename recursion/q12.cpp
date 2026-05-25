#include<iostream>
#include<vector>
#include<string>
using namespace std;

    bool isValid(vector<string>& board , int row , int col , int n){
        //no need to check that row as we always do row + 1

        //checking particular col
        int tempRow = row - 1;
        while(tempRow >= 0){
            if(board[tempRow][col] == 'Q'){
                return false;
            }
            tempRow--;
        }

        //checking diagonal
        int i = row-1;
        int j = col-1;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        i = row-1;
        j = col+1;

        while(i >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void tryingAllCombos(vector<string>& board , int row , int n , vector<vector<string>>& answer){

        if(row == n){
            answer.push_back(board);
            return;
        }

        //trying to place a queen on each row
        //for each row try every col

        for(int i = 0 ; i < n ; i++){
            
            board[row][i] = 'Q';

            if(isValid(board , row , i , n)){
                tryingAllCombos(board , row + 1 , n , answer);
            }

            board[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;

        vector<string> board(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                board[i]+= '.';
            }
        }

        tryingAllCombos(board , 0 , n , answer);

        return answer;
    }