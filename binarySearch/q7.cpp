#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//koko eating bananas
//TC : O(N * log(max(piles[i])))
//SC : O(1)


int rateOfEating(vector<int>& piles , int rate){
        int hrs = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            
            int groups = piles[i] / rate;
            int left = piles[i] % rate;

            hrs += (groups);

            if(left != 0) hrs++;
        }

        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;

        for(int x : piles){
            right = max(right , x);
        }

        int k = INT_MAX;

        while(left <= right){
            int mid = (left + right)/2;

            int timeTaken = rateOfEating(piles , mid);

            if(timeTaken <= h){//eating too fast , move towards slower rate , store answer
                k = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }   
        }

        return k;
    }