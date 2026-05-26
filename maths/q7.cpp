#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

    bool primeCheck(int number){
        if(number <= 1) return false;
        if(number == 2) return true;
        if (number % 2 == 0) return false;

        for(int i = 3 ; i <= (number / 2) ; i++){
            if(number % i == 0) return false;
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1 , true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2 ; i * i <= right ; i++){
            if(primeCheck(i)){
                for(int j = 2*i ; j <= right ; j+= i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i = left ; i <= right ; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }

        if(primes.size()<2){
            return {-1,-1};
        }

        int minDiff = INT_MAX;
        vector<int> answer(2);

        for(int i = 1 ; i < primes.size() ; i++){
            if(primes[i] - primes[i-1] < minDiff){
                minDiff = primes[i] - primes[i-1];
                answer[0] = primes[i-1];
                answer[1] = primes[i];
            }
        }

        return answer;
    }