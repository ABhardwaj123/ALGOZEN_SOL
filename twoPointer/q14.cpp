#include<iostream>
#include<vector>
using namespace std;

    int cntSubstr(string s , int k){
        int left = 0;
        int right = 0;
        int cnt = 0;
        
        vector<int> presence(3 , 0);
        vector<int> cntChar(3 , 0);

        while(right < s.size()){

            if(s[right] == 'a'){
                presence[0]=1;
                cntChar[0]++;
            }else if(s[right] == 'b'){
                presence[1]=1;
                cntChar[1]++;
            }else{
                presence[2]=1;
                cntChar[2]++;
            }

            if(presence[0] + presence[1] + presence[2] > k){

                while(left < s.size() && (presence[0] + presence[1] + presence[2] > k)){
                    cntChar[s[left] - 97]--;

                    if(cntChar[s[left] - 97] == 0){
                        presence[s[left] - 97] = 0;
                    }

                    left++;
                }
            }

            if(presence[0] + presence[1] + presence[2] <= k){
                cnt += right - left + 1;
            }

            right++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) {
        //number of substring containing atleast 3 chars - number of substring containing atleast 2 
        int v1 = cntSubstr(s , 3);
        int v2 = cntSubstr(s , 2);

        return v1 - v2;
    }