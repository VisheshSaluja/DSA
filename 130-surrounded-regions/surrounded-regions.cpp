class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c){
        if(r<0 || c<0 || r==board.size() || c==board[0].size() || board[r][c]!= 'O'){
            return;
        }

        board[r][c] = 'T';
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r, c-1);
        dfs(board, r, c+1);
    }

    void solve(vector<vector<char>>& board) {

        int ROWS = board.size();
        int COLS = board[0].size();
        int i=0;
        int j=0;

        //1. Capturing unsurrounded region (O -> T): DFS
        for(auto r=0;r<ROWS;r++){
            
            if(board[r][0]=='O')
                dfs(board, r, 0);
            if(board[r][COLS-1]=='O') dfs(board, r, COLS-1);
            
        }

        for(auto c=0;c<COLS;c++){
                if(board[0][c]=='O')
                    dfs(board, 0, c);
                if(board[ROWS-1][c]=='O') dfs(board, ROWS-1, c);
            }

        //2. Capturing surrounded region (O -> X): For loops

        for(auto r=0;r<ROWS;r++){
            for(auto c=0;c<COLS;c++){
                if(board[r][c]=='O') board[r][c] = 'X';
                if(board[r][c]=='T') board[r][c] = 'O';
            }
        }

        //3. Uncapturing unsurrounded regions (T -> O): For loops



        
        
    }
};