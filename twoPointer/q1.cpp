#include<iostream>
#include<string>
using namespace std;

//checking if a string is a palindrome or not
//TC : O(N)
//SC : O(1)

bool isPalindrome(string s) {
        int left= 0;
        int right = s.size()-1;

        while(left<=right){
            if(!isalnum((unsigned char)s[left])){
                left++;
            }else if(!isalnum((unsigned char)s[right])){
                right--;
            }else{
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }else{
                    left++;
                    right--;
                }
            }
        }

        return true;
    }