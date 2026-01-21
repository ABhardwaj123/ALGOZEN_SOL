#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int i = 0;
        int n = nums.size();

        while(i < n && nums[i] < 0 && k > 0){
            nums[i] = -nums[i];
            k--;
            i++;
        }

        if(i < n && nums[i] == 0){
            k=0;
        }
        else{
            k=k%2;
        }

        sort(nums.begin() , nums.end());

        if(k == 1){
            nums[0] = - nums[0];
        }

        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        return sum;
    }