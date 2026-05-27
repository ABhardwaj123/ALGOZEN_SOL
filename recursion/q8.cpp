#include<iostream>
#include<vector>
using namespace std;

    bool palindrome_check(string s, int start , int end){

        while(start < end){

            if(s[start] != s[end]){
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
    void generate_partitions(int index ,vector<vector<string>>& result , vector<string>& ans , string s){
        if(index == s.size()){
            result.push_back(ans);
            return;
        }

        for(int i = index ; i < s.size() ; i++){
            if(palindrome_check(s , index , i)){
                ans.push_back(s.substr(index , i - index + 1)); //imp line
                generate_partitions(i + 1 , result , ans , s);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> result;
        vector<string> ans;

        generate_partitions(0 , result , ans , s);

        return result;
    }
