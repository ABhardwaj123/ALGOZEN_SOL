#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//product of array except self

vector<int> productExceptSelf(vector<int>& nums) {
        int prefix_prod = 1;
        int postfix_prod = 1;

        vector<int> prefix;
        vector<int> suffix;

        prefix.push_back(1);
        suffix.push_back(1);

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            prefix_prod *= nums[i];
            prefix.push_back(prefix_prod);
        }

        for(int i = nums.size() - 1 ; i>0 ; i--){
            postfix_prod *= nums[i];
            suffix.push_back(postfix_prod);
        }

        reverse(suffix.begin() , suffix.end());

        vector<int> answer;

        for(int i = 0 ; i < prefix.size() ; i++){
            answer.push_back(prefix[i] * suffix[i]);
        }

        return answer;

    }