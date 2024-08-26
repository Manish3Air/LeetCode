class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        
    if (n == 0) return {};

    vector<int> result(n, 1), prefix(n,1), suffix(n,1);

    
    for (int i = 1,j=n-2; i < n,j>=0; i++,j--) {
        prefix[i] = arr[i-1] * prefix[i-1];
        suffix[j] = arr[j+1] * suffix[j+1];
    }
for(int i=0;i<n;i++){
    result[i] = prefix[i] * suffix[i];
}
    return result;
    }
};