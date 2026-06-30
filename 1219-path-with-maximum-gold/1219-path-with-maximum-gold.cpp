class Solution {
public:
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    void solve(int i,int j ,vector<vector<int>>& vis,int count,int& max_amount,int& n, int& m,vector<vector<int>>& grid){
        if((i>=n||j>=m||i<0||j<0)||grid[i][j]==0||vis[i][j]==1){
            max_amount = max(max_amount,count);
            return;
        }
        vis[i][j] = 1;
        for(int k = 0;k<4;k++){
            int r = i + dr[k];
            int c = j + dc[k];
            solve(r,c,vis,count+ grid[i][j],max_amount,n,m,grid);
        }
        vis[i][j] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> temp = vis;
        int max_amount = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!=0){
                    solve(i,j,vis,0,max_amount,n,m,grid);
                }
                vis = temp;
            }
        }
        return max_amount;
    }
};