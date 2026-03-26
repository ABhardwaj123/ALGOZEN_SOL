#include<iostream>
#include<vector>

bool isPrime(int n){
        if(n == 2) return true;
        if(n % 2 == 0) return false;

        for(int i = 2; i <= (n/2) ; i++){
            if(n % i == 0) return false;
        }

        return true;
    }
    
    bool isUgly(int n) {
        if(n == 1 || n == 2) return true;

        for(int i = 3 ; i <= n/2 ; i++){
            if(n % i == 0 && isPrime(i)){
                if(i != 2 && i != 3 && i != 5){
                    return false;
                }
            }
        }
        
        return true;
    }