#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;  
        int currentDepth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);  
            }
            if (s[i] == ')') {
                currentDepth--;
            }
        }
        return maxDepth;
    }
};
