#include <bits/stdc++.h>
using namespace std;

//to find minimum element in a rotated sorted array
//time complexity : O(log N)
//space complexity : O(1)

int findMin(vector<int>& nums) {
        int mini= INT_MAX;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[left] <= nums[mid]){//left sorted
                mini = min(mini , nums[left]);
                left = mid+1;
            }
            else{//right sorted
                mini = min(mini , nums[mid]);
                right = mid-1;
            }
        }

        return mini;
    }

int main(){
    vector<int> nums = {3,4,5,1,2};

    int min_value = findMin(nums);

    return 0;
}