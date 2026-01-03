#include<iostream>
#include<algorithm>
#include<math.h>
#include <climits>
using namespace std;

//reversing an integer
//the commented out approach was my original solution
//the original function has better code quality
//time complexity : O(d) {d -> number of digits}
//space complexity : O(1)

int reverse(int x){
    int num = 0;

    while(x != 0){
        int rem = x % 10;

        if(num > INT_MAX / 10 || (num == INT_MAX / 10 && rem > 7)) return 0;

        if(num < INT_MIN / 10 || (num == INT_MIN && rem < -8)) return 0;

        num = (num * 10) + rem;
        x = x/10;
    }

    return num;
}

// int reverse(int x) {
//         int neg = (x < 0) ? 1 : 0;


//         if(x == INT_MIN) return 0;

//         long long num = abs(x);
//         long long rev = 0;

//         while(num != 0){
//             int rem = num % 10;

//             if(rev * 10 > INT_MAX){
//                 return 0;
//             }

//             rev = (rev * 10) + rem;

//             num = num/10;
//         }

//         if(neg){
//             return -rev;
//         }

//         return rev;
//     }