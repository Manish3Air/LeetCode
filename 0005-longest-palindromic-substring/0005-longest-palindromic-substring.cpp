class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        string max_substr = s.substr(0,1);

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                
                left--;
                right++;
            }
            return s.substr(left + 1,right - left - 1);
        };

        for (int i = 0; i < n; i++) {
            string odd = expandAroundCenter(i, i);     
            string even = expandAroundCenter(i, i + 1); 
                if (odd.size() > max_substr.size()) {
                    max_substr = odd;
                }
                if (even.size() > max_substr.size()) {
                    max_substr = even;
                }
        }

        return max_substr;
    }
};
