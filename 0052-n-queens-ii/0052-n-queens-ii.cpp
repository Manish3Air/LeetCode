class Solution {
public:
    
    bool isValid(int row, int col, vector<string> board, int n) {
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    int formQueen(int col, int n,vector<string> board) {
        if (col == n) {
            return 1;
        }
        int count = 0;
        for (int row = 0; row < n; row++) {
            if (isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                count+=formQueen(col + 1, n, board);
                board[row][col] = '.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return formQueen(0, n, board);
    }
};