class Solution {
public:
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    void dfs(int r,int c,vector<vector<int>>& vis, vector<vector<char>>& grid,int n,int m){
        vis[r][c] = 1;
        for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==0){
                dfs(nr,nc,vis,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='0') vis[i][j] = 1;
            }
        }
        int island = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]!=1){
                    dfs(i,j,vis,grid,n,m);
                    island++;
                }
            }
        }
        return island;
    }
};