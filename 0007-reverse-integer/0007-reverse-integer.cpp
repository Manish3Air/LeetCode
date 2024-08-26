// class Solution {
// public:
//     int reverse(int x) {
//     int num = x;
//     long reverse = 0;
//     while(x!=0)
//     {
//         int digit = x%10;
//         reverse = reverse*10+digit;
//         x = x/10;
//     }
//     if(reverse<INT_MIN || reverse>INT_MAX){
//         return 0;
//     }
//     return (int)reverse;
//     }
// };
class Solution {                      
public:
    int reverse(int x) {
        int r=0;       
        while(x){
         if (r>INT_MAX/10 || r<INT_MIN/10) return 0; 
         r=r*10+x%10; 
         x=x/10;     
        } 
        return r;  
    }
}; 