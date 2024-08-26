#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int mini = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            mini = min(mini, (int)strs[i].size());
        }
        
        string result;
        for (int j = 0; j < mini; j++) {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] != c) {
                    return result;
                }
            }
            result += c;
        }
        return result;
    }

};