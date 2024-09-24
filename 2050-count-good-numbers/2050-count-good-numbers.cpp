class Solution {
public:
    int pf(long long num, long long pow) {
        long long ans = 1;
        int mod = 1e9 + 7;
        while (pow > 0) {
            if (pow % 2 == 0) {
                pow /= 2;
                num = (num * num) % mod;
            } else {
                ans = (ans * num) % mod;
                pow--;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = n / 2;
        long long odd = n - even;
        int mod = 1e9 + 7;
        long long result = (1LL * pf(5, odd) * pf(4, even)) % mod;

        return (int)result;
    }
};
