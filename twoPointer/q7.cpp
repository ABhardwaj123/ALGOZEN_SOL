#include<iostream>
#include<vector>

using namespace std;

    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        int length = 0;
        int maxLength = 0;
        int zeroCnt = 0;

        while(right < nums.size()){

            if(nums[right] == 0){
                zeroCnt++;
            }

            if(zeroCnt > k){
                if(nums[left] == 0){
                    zeroCnt--;
                }
                left++; 
            }

            if(zeroCnt <= k){
                length = right - left + 1;
                maxLength = max(maxLength , length);
            }

            right++;
        }

        return maxLength;

        //below is the solution broken into two cases : 1-> k = 0 , 2-> k != 0
        
        // int left = 0;
        // int right = 0;

        // int length = 0;
        // int max_length = INT_MIN;

        // if(k == 0){
        //     int l = 0;
        //     int r = 0;
        //     int ln = 0;
        //     int ml = 0;

        //     while(r < nums.size()){

        //         if(nums[r] == 0){

        //             while(r < nums.size() && nums[r] == 0){
        //                 r++;
        //             }

        //             if(r != nums.size()){
        //                 l = r;
        //                 ln = 1; 
        //             }
                    

        //         }else{

        //             ln = r - l + 1;
        //         }

        //         ml = max(ml , ln);
        //         r++;
        //     }

        //     return ml;
        // }

        // while(right < nums.size()){

        //     if(nums[right] == 1){

        //         length = right - left + 1;

        //     }else{

        //         if(k > 0){
        //             k--;
        //         }else{
        //             while(k == 0){
        //                 if(nums[left] == 0){
        //                     k++;
        //                 }
        //                 left++;
        //             }
        //             k--;
                    
        //         }
        //         length = right - left + 1;

        //     }

        //     max_length = max(max_length , length);
        //     right++;
        // }

        // return max_length;

    }