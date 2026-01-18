#include<iostream>
#include<vector>
using namespace std;

//finding majority element by moore's voting algorithm
//TC: O(N)
//SC : O(1)

//logic : if we get a element and freq is 0 , it is the beginning of it's majority
//everytime a same number comes , its majority increases else freq is decremented(we get opposition to current majority)

int majorityElement(vector<int>& nums) {
        int freq = 0;
        int max_ele = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(freq == 0){
                freq = 1;
                max_ele = nums[i];
            }else if(nums[i] == max_ele){
                freq++;
            }else{
                freq--;
            }
        }

        return max_ele;
    }