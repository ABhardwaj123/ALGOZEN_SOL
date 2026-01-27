#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//container with max water
//TC: O(N)
//SC : O(1)

int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int max_area = INT_MIN;

        while(left < right){
            int h = min(height[left] , height[right]);
            int length = right - left;

            int current_area = h * length;
            max_area = max(max_area , current_area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        
        }

        return max_area;
    }