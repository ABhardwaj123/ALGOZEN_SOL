#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//searching for an element in a rotated sorted array
//time complexity : O(log n)
//space complexity : O(1)

int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[left] <= nums[mid]){//left sorted
                if(target >= nums[left] && target < nums[mid]){//it must be in the left sorted side
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }else{//right sorted
                if(target > nums[mid] && target <= nums[right]){//it is in the right sorted side
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }

        return -1;
    }

int main(){
    vector<int> nums ={4,5,6,7,0,1,2};
    int target = 0;

    int index = search(nums , target);
}