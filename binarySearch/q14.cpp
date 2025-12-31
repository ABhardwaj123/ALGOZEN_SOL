#include<bits/stdc++.h>
using namespace std;

//finding an element in a 2d matrix that is sorted row wise 
//time complexity : O(log(m*n)) {m-> number of rows , n->number of columns}
//space complexity : O(1)


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;

        int rows = matrix.size();
        int cols = matrix[0].size();

        while(low <= high){
            int mid = (high - low)/ 2 + low;
            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;
    }

int main(){
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 3;

    bool found = searchMatrix(matrix , target);

}

