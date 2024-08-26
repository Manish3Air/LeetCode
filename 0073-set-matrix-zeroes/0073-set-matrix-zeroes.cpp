class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> col;
         vector<int> row;
         int n=matrix.size();
         int m=matrix[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) 
	  {
		  col.push_back(j);
		  row.push_back(i);
      }
    }
  }
int N=col.size();
for(int i=0;i<N;i++){
    for (int l = 0; l < n; l++) {
      matrix[l][col[i]] = 0;
    }
}
int M=row.size();
for(int j=0;j<M;j++){
    for (int k = 0; k < m; k++) {
      matrix[row[j]][k] = 0;
    }
}
    }
};