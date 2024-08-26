class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = (long long )x;
        long long num = 0;
        int digit = 0;
        while(x>0){
            digit = x%10;
            num = num * 10 + digit;
            x = x/10;
        }
        if(num == temp){
            return true;
        }
        else {
           return false;
        }
    }
};