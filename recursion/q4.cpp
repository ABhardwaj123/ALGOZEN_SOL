#include<iostream>
#include<vector>
using namespace std;

//combination sum1 {make target by using given number any number of times}
//TC : O((2^N) * K)
//2^N for the recursion calls and K for adding the answer to the final data structure
//SC : O(N * K) {k : total possible combinations and N is the average size of each combination}


void generateSum(vector<vector<int>>& result , vector<int>& answer , int idx , vector<int>& candidates , int target){
        if(idx == candidates.size()){
            if(target == 0){
                result.push_back(answer);
            }

            return;
        }

        if(candidates[idx] <= target){
            answer.push_back(candidates[idx]);
            generateSum(result , answer , idx , candidates , target - candidates[idx]);

            answer.pop_back();
        }

        generateSum(result , answer , idx+1 , candidates , target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> answer;
        int idx = 0;

        generateSum(result , answer , idx , candidates , target);

        return result;
    }