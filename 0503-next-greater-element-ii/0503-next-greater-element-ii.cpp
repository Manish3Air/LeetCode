class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<i+n;j++){
                int index=j%n;
                if(a[index] > a[i]) {
                    ans[i] = a[index];
                break;
                }
            }
        }
        return ans;
    }
};