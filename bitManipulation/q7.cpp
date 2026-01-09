#include<iostream>
#include<vector>
using namespace std;

//single number
//TC : O(N)
//SC : O(1)

int singleNumber(vector<int>& nums) {
        int answer = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            answer ^= nums[i];
        }

        return answer;
    }