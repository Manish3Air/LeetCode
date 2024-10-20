#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // Define 32-bit integer limits
        const int minimum = -(1 << 31); // -2147483648
        const int maximum = (1 << 31) - 1; // 2147483647
        
        bool signve = true;
        int fv = 10;
        long long res = 0; // Use long long to handle overflow
        int n = s.size();
        bool check = true;
        for(int i = 0; i < n; i++){
            if(s[i] == '-' && check){
                signve = false;
                check = false; // After processing sign, disable further checking
                continue;
            }
            if(s[i] == '+' && check){ // Handle positive sign as well
                check = false;
                continue;
            }
            if(s[i] == ' ' && check) continue; // Skip leading spaces
            if(s[i] >= '0' && s[i] <= '9'){
                check = false;
                res = (res * fv) + (s[i] - '0');

                // Check for overflow during computation
                if (signve && res > maximum) return maximum;
                if (!signve && -res < minimum) return minimum;
            } else {
                break; // Non-numeric character
            }
        }

        // Apply sign and check bounds
        if (!signve) res = -res;

        // Round result if out of bounds
        if (res < minimum) return minimum;
        if (res > maximum) return maximum;

        return res;
    }
};
