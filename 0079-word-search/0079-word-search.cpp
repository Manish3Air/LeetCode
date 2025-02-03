class Solution {
public:
  bool check(int i, int j, vector<vector<char>>& mat, string& word, int pos, int n, int m, vector<vector<bool>>& visited) {
    if (pos == word.size()) return true;               
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    if (visited[i][j] || mat[i][j] != word[pos]) return false;

    visited[i][j] = true;

    bool found = check(i + 1, j, mat, word, pos + 1, n, m, visited) ||
                 check(i - 1, j, mat, word, pos + 1, n, m, visited) ||
                 check(i, j + 1, mat, word, pos + 1, n, m, visited) ||
                 check(i, j - 1, mat, word, pos + 1, n, m, visited);

    visited[i][j] = false;

    return found;
}

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) { 
                if (check(i, j, board, word, 0, n, m, visited))
                    return true;
            }
        }
    }
    return false;
    }
};