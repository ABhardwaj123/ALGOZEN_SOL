#include<iostream>
#include<vector>
using namespace std;

//two sum : input array is sorted
//two pointer approach
//time complexity : O(N)
//space complexity : O(1)

vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> answer;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                answer.push_back(left+1);
                answer.push_back(right+1);
                break;
            }
            else if(sum > target){
                right--;
            }else{
                left++;
            }
        }

        return answer;
    }

int main(){
    vector<int> numbers = {2,7,11,15};
    vector<int> answer = twoSum(numbers , 9);

    return 0;
}