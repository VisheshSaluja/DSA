class Solution {
public:

    void bfs(vector<vector<char>> &grid, int i, int j){

        int ROW = grid.size();
        int COLUMN = grid[0].size();

        if(i<0 || i>=ROW || j<0 || j>=COLUMN || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        bfs(grid, i-1, j);
        bfs(grid, i+1, j);
        bfs(grid, i, j-1);
        bfs(grid, i, j+1);

    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};