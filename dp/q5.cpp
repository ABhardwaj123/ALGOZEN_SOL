#include<iostream>
#include<vector>
using namespace std;

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;

        int cnt=0;
        int seqStart = 0;
        int diff = nums[0] - nums[1];

        for(int i = 1 ; i<n ; i++){

            int curr_diff = nums[i-1] - nums[i];

            if(curr_diff == diff && i - seqStart >= 2) cnt += (i - seqStart - 1);

            if(curr_diff != diff){
                seqStart = i-1;
                diff = curr_diff;
            }
        }

        return cnt;
    }