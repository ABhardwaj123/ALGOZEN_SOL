#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

void combinations(int idx , string& code , vector<string>& answer , string& digits , map<int,vector<char>>& mpp){
        if(idx == digits.size()){
            answer.push_back(code);
            return;
        }

        int current_num = digits[idx] - '0';
        int size = (current_num == 7 || current_num == 9) ? 4 : 3;

        for(int i = 0 ; i < size ; i++){
            code.push_back(mpp[current_num][i]);
            combinations(idx + 1 , code , answer , digits , mpp);

            code.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int ,vector<char>> mpp;
        mpp[2] = {'a' , 'b' , 'c'};
        mpp[3] = {'d' , 'e' , 'f'};
        mpp[4] = {'g' , 'h' , 'i'};
        mpp[5] = {'j' , 'k' , 'l'};
        mpp[6] = {'m' , 'n' , 'o'};
        mpp[7] = {'p' , 'q' , 'r' , 's'};
        mpp[8] = {'t' , 'u' , 'v'};
        mpp[9] = {'w' , 'x' , 'y' , 'z'};

        vector<string> answer;
        string code = "";

        combinations(0 , code , answer, digits , mpp);

        return answer;

    }