#include<iostream>
#include<vector>
#include <climits>
#include <algorithm>
using namespace std;

//removing an element
//TC : O(N)
//SC : O(1)


int removeElement(vector<int>& nums, int val) {
        int count = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == val){
                nums[i] = INT_MAX;
            }else{
                count++;
            }
        }

        sort(nums.begin() , nums.end());

        return count;
    }