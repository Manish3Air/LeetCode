class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int r = 0, l = 0, maximum = 0, len = 0;
        vector<int> hash(256, 0);
        
        while (r < n) {
            ++hash[s[r]];
            int maxfreq = *max_element(hash.begin(), hash.end());
            
            while ((r - l + 1) - maxfreq > k) {
                --hash[s[l]];
                l++;
            }
            
            len = r - l + 1;
            maximum = max(maximum, len);
            r++;
        }
        
        return maximum;
    }
};
