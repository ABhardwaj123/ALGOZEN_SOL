#include<iostream>
#include<vector>
using namespace std;

//counting number of set bits


vector<int> countBits(int n) {
        
        vector<int> count;
        if(n < 0){
            return count;
        }

        count.push_back(0);

        for(int i = 1 ; i<=n ; i++){
            int set = 0;
            int temp = i;
            while(temp != 0){
                if((temp & 1) == 1){
                    set++;
                }

                temp = temp>>1;
            }

            count.push_back(set);
        }

        return count;
    }