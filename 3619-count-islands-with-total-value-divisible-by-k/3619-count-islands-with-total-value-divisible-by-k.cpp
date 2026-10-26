class Solution {
public:
    int MOD = 1e9 + 7;
    int dr[4] = {0,1,-1,0};
    int dc[4] = {1,0,0,-1};
    void dfs(int r,int c, long long& val,vector<vector<int>>& grid,int n,int m){
        val = (val + grid[r][c]);
        grid[r][c] = 0;
        for(int i = 0;i<4;i++){
            int nr  = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]>0){
                dfs(nr,nc,val,grid,n,m);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int valid_islands = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]>0){
                    long long val = 0;
                    dfs(i,j,val,grid,n,m);
                    if(val!=0&&val%k==0) valid_islands++;
                }
            }
        }
        return valid_islands;
    }
};