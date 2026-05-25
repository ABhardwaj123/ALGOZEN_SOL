#include<iostream>
#include<vector>
using namespace std;

    void tryingAllCombos(int n , int start , int nCount , int k , vector<int>& digits , vector<vector<int>>& result , vector<int>& answer){

        if(n == 0){// n is our target
            if(nCount == k){
                result.push_back(answer);
            }

            return;
        }

        for(int i = start ; i < digits.size() ; i++){
            if(n >= digits[i]){
                answer.push_back(digits[i]);
                tryingAllCombos(n - digits[i] , i + 1 , nCount + 1 , k , digits , result , answer);
                answer.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> result;
        vector<int> answer;

        vector<int> digits = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};


        tryingAllCombos(n , 0 , 0 , k , digits , result , answer);
        return result;

    }