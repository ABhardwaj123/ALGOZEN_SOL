#include<iostream>
#include<string>
using namespace std;

//finding first occurrence in the string
//TC: O(N)
//SC : O(N)

int strStr(string haystack, string needle) {
        int left = 0;
        int right = needle.size() - 1;

        while(right < haystack.size()){
            string str = haystack.substr(left , right - left + 1);

            if(str == needle){
                return left;
            }

            left++;
            right++;
        }

        return -1;   
    }