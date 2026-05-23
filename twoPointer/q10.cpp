#include<iostream>
#include<vector>
#include<map>
using namespace std;

    int cntSubarrays(vector<int>& nums , int k){
        map<int , int> mpp;
        
        int left = 0;
        int right = 0;
        int cnt = 0;

        while(right < nums.size()){

            mpp[nums[right]]++;

            if(mpp.size() > k){
                while(mpp.size() > k){
                    mpp[nums[left]]--;

                    if(mpp[nums[left]] == 0){
                        mpp.erase(nums[left]);
                    }

                    left++;
                }
            }

            if(mpp.size() <= k){
                cnt += (right - left + 1);
            }

            right++;
        }

        return cnt; 
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int v1 = cntSubarrays(nums , k);
        int v2 = cntSubarrays(nums , k - 1);

        return v1 - v2;
    }