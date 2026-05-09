class Solution {
   public:
    bool isValid(char ch) { return ch >= '1' && ch <= '9'; }
    bool isValidRow(vector<char>& a) {
        set<char> st;
        for (int i = 0; i < 9; i++) {
            if (a[i] == '.') continue;
            if (st.count(a[i]) || !isValid(a[i])) return false;
            st.insert(a[i]);
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 * 3 check
        // row check
        // col check
        int n = board.size();
        int m = board[0].size();
        if (n != 9 || m != 9) return false;  // basic check

        // row check
        for (int i = 0; i < n; i++) {
            if (!isValidRow(board[i])) {
                return false;
            }
        }

        // col check
        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = 0; j < n; j++) {
                if (board[j][i] == '.') continue;
                if (st.count(board[j][i]) || !isValid(board[j][i])) return false;
                st.insert(board[j][i]);
            }
        }

        // 3 * 3

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                set<char> st;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] == '.') continue;
                        if (st.count(board[x][y]) || !isValid(board[x][y])) return false;
                        st.insert(board[x][y]);
                    }
                }
            }
        }

        return true;
    }
};
