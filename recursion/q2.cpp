#include<iostream>
#include<vector>
using namespace std;

//generating all subsets
//time complexity : O(N * (2^N))
//TC explanation : 2^N for all the recursion calls and N for copying the answer vector in final result vector
//N for copying is worst case as to copy a vector of size K it takes O(K)

//space complexity : O(N * (2^N)) + O(N)
//SC explanation : N for the recursive stack space {N is maximum height of recursive tree} 
//for O(N * (2^N)) : 2^N are total number of subsets and N is the size of each subset (worst case N)

void generateSubsets(vector<vector<int>>& result , int idx , int n , vector<int>& answer , vector<int>& nums){
        if(idx == n){
            result.push_back(answer);
            return;
        }

        answer.push_back(nums[idx]);
        generateSubsets(result , idx + 1 , n , answer , nums);

        answer.pop_back();
        generateSubsets(result , idx + 1 , n , answer , nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> answer;
        
        int n = nums.size();
        int idx = 0;

        generateSubsets(result , idx , n , answer , nums);

        return result;
    }

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
}