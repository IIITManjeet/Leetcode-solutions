class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n = 0, m = 0;

    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        if (idx >= word.size()) return true;
        if (!isValid(i, j) || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '\0';
        for (int k = 0; k < 4; k++) {
            int newI = i + dx[k];
            int newJ = j + dy[k];
            if (dfs(newI, newJ, board, word, idx + 1)) return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
