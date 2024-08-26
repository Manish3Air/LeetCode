class Solution {
public:
    
int solve(int n, vector<int>& arr) {
    int prev = arr[0];   
    int prev2 = 0;       
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  
        if (i > 1)
            pick += prev2;  
        
        int nonPick = 0 + prev;  
        
        int cur_i = max(pick, nonPick);  
        prev2 = prev;   
        prev = cur_i;   
    }
    
    return prev;  
}

    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(n-1,temp1),solve(n-1,temp2));
    }
};