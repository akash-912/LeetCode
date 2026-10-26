class Solution {
public:
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<char>>& board,int n,int m){
        board[r][c] = 'O';
        grid[r][c] = 'X';
        for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]=='O'){
                dfs(nr,nc,grid,board,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> grid = board;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                board[i][j] = 'X';
            }
        }
        for(int i = 0;i<n;i++){
            if(grid[i][0]=='O'){
                dfs(i,0,grid,board,n,m);
            }
            if(grid[i][m-1]=='O'){
                dfs(i,m-1,grid,board,n,m);
            }
        }
        for(int i = 0;i<m;i++){
            if(grid[0][i]=='O'){
                dfs(0,i,grid,board,n,m);
            }
            if(grid[n-1][i]=='O'){
                dfs(n-1,i,grid,board,n,m);
            }
        }
        
    }
};