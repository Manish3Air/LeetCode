class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N=prices.size();
    int Maxi=0;
    int min=prices[0];
    for(int i=1;i<N;i++){
    if(prices[i]>min){
       int maxi=(prices[i]-min);
       Maxi=max(maxi,Maxi);
    }
    if(prices[i]<min){
        min=prices[i];
    }
    }
    return Maxi;
    }
};