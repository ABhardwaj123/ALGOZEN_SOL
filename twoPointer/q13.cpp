#include<iostream>
#include<vector>
using namespace std;

    int cntSubarrays(vector<int>& nums , int k){

        int left = 0;
        int right = 0;
        int cnt = 0;
        int oddCnt = 0;

        while(right < nums.size()){
            if(nums[right] % 2 != 0){
                oddCnt++;
            }

            if(oddCnt > k){
                while(left < nums.size() && oddCnt > k){
                    if(nums[left] % 2 != 0){
                        oddCnt--;
                    }
                    left++;
                }
            }

            if(oddCnt <= k){
                cnt += (right - left + 1);
            }

            right++;
        }
        
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //number of subarrays with at least k odd numbers - number of subarrays with at least k -1 odd numbers
        int v1 = cntSubarrays(nums , k);
        int v2 = cntSubarrays(nums , k -1);

        return v1 - v2;
    }