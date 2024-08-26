class Solution {
public:
    int maxArea(vector<int>& height) {
        int N=height.size();
        int Max=0;
        int low=0;
       int high=N-1;
        while(low<high){
            if(height[low] < height[high]){
                Max=max(Max,(height[low]*(high-low)));
                low++;
            }
            else{
                Max=max(Max,(height[high]*(high-low)));
                  high--;
            }
        }
        return Max;
    }
    //     int Max=INT_MIN;
    //    for(int i=0;i<N;i++){
    //        for(int j=i;j<N;j++){
    //            if(height[i]==height[j]){
    //                int Q=height[i]*(j-i);
    //                Max=max(Max,Q);
    //            }
    //            else{
    //            int P=min(height[i],height[j]);
    //            Max=max(Max,(P*(j-i)));
    //            }
    //        }
    //    }
    //    return Max;
    // }
};