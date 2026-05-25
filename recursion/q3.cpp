#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

    void generate_combos(int idx , vector<vector<int>>& ans , vector<int>& result , vector<int>& nums){
        //base case
        if(idx == nums.size()){
            return;
        }

        for(int i = idx ; i < nums.size() ; i++){
            // repetition condition
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }

            //addition condition
            result.push_back(nums[i]);
            ans.push_back(result);
            generate_combos(i+1 , ans , result , nums);

            result.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;

        sort(nums.begin() , nums.end());

        generate_combos(0 , ans , result , nums);
        vector<int> empty;

        ans.push_back(empty);

        return ans;
    }