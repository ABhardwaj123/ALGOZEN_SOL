#include<iostream>
using namespace std;

//is power of two or not

bool isPowerOfTwo(int n) {
        int count = 0;

        if(n == 0) return false;

        while(n != 0){

            if(((n & 1) == 1) && count >= 1){
                return false;
            }else if((n & 1) == 1){
                count++;
            }

            n = n>>1;
        }

        return true;
    }