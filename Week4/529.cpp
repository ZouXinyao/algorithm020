class Solution {
public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void dfs(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        for(int i = 0; i < 8; i++) {
            int bx = x + dir_x[i];
            int by = y + dir_y[i];
            if(bx < 0 || bx >= board.size() || by < 0 || by >= board[0].size()) continue;
            if(board[bx][by] == 'M') cnt++;
        }
        if(cnt > 0) board[x][y] = cnt + '0';
        else{
            board[x][y] = 'B';
            for(int i = 0; i < 8; i++) {
                int bx = x + dir_x[i];
                int by = y + dir_y[i];
                if(bx < 0 || bx >= board.size() || by < 0 || by >= board[0].size() || board[bx][by] != 'E') continue;
                dfs(board, bx, by);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') board[x][y] = 'X';
        else dfs(board, x, y);

        return board;
    }
};
