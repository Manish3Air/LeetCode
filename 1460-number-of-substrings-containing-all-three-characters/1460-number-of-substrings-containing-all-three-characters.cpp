class Solution {
public:
 int countsubstrings(string s, int k) {
        int N = s.size();
         int count = 0;
        int l = 0, r = 0;
        unordered_map<char,int> mp;
        while (r < N) {
            mp[s[r]]++;
            while(mp.size() > k) {
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            if (mp.size() <= k) {
                count += r - l + 1;
            }
            r++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        return countsubstrings(s,3) - countsubstrings(s,2);
    }
};