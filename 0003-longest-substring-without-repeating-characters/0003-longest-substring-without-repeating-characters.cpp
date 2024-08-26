class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maximum=0;
        int N=s.size();
        vector<int> hasharr(256,-1);
        while(r<N){
            if(hasharr[s[r]]!=-1){
                if(hasharr[s[r]]>=l){
                    l=hasharr[s[r]]+1;
                }
            }
            int length=r-l+1;
            maximum=max(maximum,length);
            hasharr[s[r]] = r;
            r++;
        }
        return maximum;
    }
};