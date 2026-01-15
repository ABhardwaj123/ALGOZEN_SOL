#include<iostream>
#include<vector>
using namespace std;

//counting primes
//kind of like sieve of eratosthenes

int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2) return 0;

        vector<int> primes(n , 1);

        for(int i = 4 ; i < n ; i+=2){
            primes[i] = 0;
        }

        for(int i = 3 ; i < n ; i++){
            if(i%2 == 0) continue;

            if(primes[i] == 1){

                for(int j = 2*i ; j < n ; j+= i){
                    primes[j] = 0;
                }
            }
        }

        int count = 0;

        for(int i = 2 ; i < n ; i++){
            if(primes[i] == 1){
                count++;
            }
        }

        return count;
    }