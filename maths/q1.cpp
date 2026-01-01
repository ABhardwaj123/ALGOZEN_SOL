#include<bits/stdc++.h>
using namespace std;

//power function (x raised to power n)
//time complexity : O(log N)
//space complexity : O(1) {not including recursive stack space}



double power(double x , long long n){
        if(n == 1) return x;

        if(n % 2 == 0){
            return power(x*x , n/2);
        }else{
            return x * power(x*x , n/2);
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        

        if(N < 0){
            x= 1/x;
            N = -N;
        }

        if(N == 0) return 1;
        if(x == 1) return 1;
        
        return power(x , N);
    }

int main(){
    double answer = myPow(2.00000 , -2);
}