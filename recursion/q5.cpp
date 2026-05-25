#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

    void generate_combos(int i , vector<vector<int>>& ans , vector<int>& result , vector<int>& candidates , int target){
        if(target==0){
            ans.push_back(result);
            return;
        }

        for(int j =i ; j< candidates.size() ; j++){

            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            
            if(candidates[j] > target){
                break;
            }

            result.push_back(candidates[j]);
            generate_combos(j+1 , ans , result , candidates , target - candidates[j]);

            result.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> result;

        sort(candidates.begin() , candidates.end());

        generate_combos(0 , ans , result , candidates , target);

        return ans;
    }