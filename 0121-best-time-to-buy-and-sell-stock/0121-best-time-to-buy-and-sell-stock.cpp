class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> max1;
        int maxi = -1;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            maxi = max(maxi,prices[i]);
            // max1.push_back(maxi);
            if(prices[i] <= maxi){
                int diff = abs(maxi-prices[i]);
                ans = max(ans,diff);
            }
        }
        // maxi = -1;
        // for(int i = 0; i < n; i++){
        //     maxi = max(maxi,abs(prices[i]-max1[n-i-1]));
        // }
        return ans;
    }
};