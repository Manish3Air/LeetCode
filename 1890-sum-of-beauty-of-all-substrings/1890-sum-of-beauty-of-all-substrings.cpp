#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; ++j) {
                mp[s[j]]++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto& it : mp) {
                    maxFreq = max(maxFreq, it.second);
                    minFreq = min(minFreq, it.second);
                }
                count += (maxFreq - minFreq);
            }
        }
        return count;
    }
};
