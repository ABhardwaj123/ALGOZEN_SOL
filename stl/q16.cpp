#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i = 0 ; i < k ; i++){
            s.insert(nums[i]);
        }

        int left = 0;
        int right = k;

        while(right < nums.size()){
            s.insert(nums[right++]);

            if(s.size() < k + 1) return true;

            s.erase(nums[left]);
            left++;
        }

        return false;

    }