class Solution {
public:
    int maxProduct(vector<int>& arr) {
         int N = arr.size();
    int maxi = INT_MIN;
    int pref = 1;
    int suff = 1;
    for(int i=0;i<N;i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *=arr[i];
        suff *=arr[N-i-1];
        maxi = max(maxi,max(pref,suff));
    }
    return maxi;
    }
};