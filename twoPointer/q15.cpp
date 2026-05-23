#include<iostream>
#include<vector>
using namespace std;

    int cntSubarrays(vector<int>& nums , int goal){
        if(goal < 0) return 0;

        int left=0;
        int right=0;
        int cnt = 0;
        int currSum=0;
        
        while(right < nums.size()){

            currSum += nums[right];

            if(currSum > goal){

                while(currSum > goal){
                    currSum -= nums[left];
                    left++;
                }
            }

            if(currSum <= goal){
                cnt += (right - left + 1);
            }

            right++;

        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        //( binary subarrays with sum <= goal ) - ( binary subarrays with sum <= (goal - 1))
         
        int v1 = cntSubarrays(nums , goal);
        int v2 = cntSubarrays(nums , goal - 1);

        return v1 - v2;
    }