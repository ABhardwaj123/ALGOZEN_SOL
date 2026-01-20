#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//finding the triangle with largest perimeter
//TC : O(N * logN) {sorting + traversal}
//SC : O(1)

int largestPerimeter(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int i = nums.size() - 1;

        while(i - 2 >= 0){
            if(nums[i-2] + nums[i-1] > nums[i]){
                return nums[i-2] + nums[i-1] + nums[i];
            }

            i--;
        }

        return 0;

    }