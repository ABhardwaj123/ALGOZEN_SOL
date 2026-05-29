#include<iostream>
#include<vector>
#include <climits>
using namespace std;

    int tryingAllCombos(int n , int curr_length , int pasteLength){
        if(curr_length >= n){
            if(curr_length > n) return 1e9;
            return 0;
        }

        int copy = INT_MAX;
        if(curr_length != pasteLength){
            copy = 1 + tryingAllCombos(n , curr_length , curr_length);
        }

        int paste = INT_MAX;
        if(pasteLength != 0){
            paste = 1 + tryingAllCombos(n , curr_length + pasteLength , pasteLength);
        }
        
        return min(copy , paste); 
    }

    int minSteps(int n) {
        
        int curr_length = 1;
        int pasteLength = 0;

        return tryingAllCombos(n , curr_length , pasteLength);
    }