#include<iostream>
#include<string>
#include<climits>
#include<map>
using namespace std;

//length of longest substring with no repeating characters
//TC : O(N) {N -> length of string}
//SC : O(1)


int lengthOfLongestSubstring(string s) {
        int max_length = INT_MIN;
        int left = 0;
        int right = 0;

        map<char,int> mpp;

        while(right < s.size()){

            if(mpp.find(s[right]) == mpp.end()){//previously not in the map

                mpp[s[right]]++;
                max_length = max(max_length , right - left + 1);

            }else{//shrinking the window because we found duplicate

                while(left <= right && mpp.find(s[right]) != mpp.end()){
                    mpp[s[left]]--;

                    if(mpp[s[left]] == 0) mpp.erase(s[left]);
                    left++;
                }

                mpp[s[right]]++;
                max_length = max(max_length , right - left + 1);
            }

            right++;
        }

        return max_length == INT_MIN ? 0 : max_length;
    }