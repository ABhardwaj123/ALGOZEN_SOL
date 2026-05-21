#include<iostream>
#include<vector>

using namespace std;

    string convert(string s, int numRows) {

        string answer = "";

        if(numRows >= 2){
            int singleCharColSize = numRows - 2;
            int colPatternLen = 1 + singleCharColSize;

            int len = s.size();
            int cols = len / (numRows + singleCharColSize);
            cols = (cols * colPatternLen);

            int rem = (len % (numRows + singleCharColSize));
            if(rem <= numRows){
                cols++;
            }else{
                cols = cols + 1 + (rem - numRows);
            }

            vector<vector<char>> matrix(numRows , vector<char>(cols , '*'));

            int idx = 0;
            int r = 0;
            int c = 0;

            while(idx < s.size()){

                while(r < numRows && idx < s.size()){
                    matrix[r][c] = s[idx];
                    idx++;
                    r++;
                }

                r-=2;
                c++;

                while(r > 0 && idx < s.size()){
                    matrix[r][c] = s[idx];
                    idx++;
                    r--;
                    c++;
                }
            }

            for(int i = 0 ; i < numRows ; i++){
                for(int j = 0 ; j < cols ; j++){
                    if(matrix[i][j] != '*'){
                        answer += matrix[i][j];
                    }
                }
            }
            
        }else{
            answer = s;
        }
        

        return answer;
    }