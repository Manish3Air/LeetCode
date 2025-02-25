class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
          stack<int> st;
        int N = arr.size();
        int maxi = 0;
        for(int i = 0; i < N; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi,(element * (nse - pse - 1)));
            }
            st.push(i);
        }
        while(!st.empty()){
                int element = arr[st.top()];
                st.pop();
                int nse = N;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi,(element * (nse - pse - 1)));
            }
        return maxi;
    }
};