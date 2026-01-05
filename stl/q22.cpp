#include<iostream>
#include<stack>
using namespace std;

//checking for valid parenthesis
//time complexity : O(N) N is length of string s
//space complexity : O(N) {worst case}

bool isValid(string s) {
        stack<char> st;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;

                if((s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') || (s[i] == '}' && st.top() != '{')){
                    return false;
                }else{
                    st.pop();
                }
            }
        }

        return st.empty();
    }