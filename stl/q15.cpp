#include<iostream>
#include<vector>
#include<string>
#include <unordered_set>
using namespace std;

    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        unordered_set<int> s;
        int longest = 1;

        for(int x : nums){
            s.insert(x);
        }

        for(auto it : s){
            if(s.find(it -1) == s.end()){//start of sequence
                int count = 1;
                int x = it;

                while(s.find(x+1) != s.end()){
                    count++;
                    x++;
                }

                longest = max(longest , count);
            }
        }

        return longest;
    }