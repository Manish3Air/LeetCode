class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M=matrix.size();
        int N=matrix[0].size();
        int low=0;
        int high=(M*N)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int Row=mid/N;
            int Col=mid%N;
            if(matrix[Row][Col]==target){
                return true;
            }
            else if(matrix[Row][Col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};