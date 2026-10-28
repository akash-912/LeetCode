class Solution {
public:
    int dfs(int r,int c, int curr,vector<vector<int>>& grid,int n,int m,vector<vector<vector<int>>>& dp){
        
        curr ^= grid[r][c];
        if(dp[r][c][curr]!=-1) return dp[r][c][curr];
        if(r==n-1&&c==m-1) return curr;
        int right = INT_MAX;
        if(c<m-1) right = dfs(r,c+1,curr,grid,n,m,dp);
        int down = INT_MAX;
        if(r<n-1) down = dfs(r+1,c,curr,grid,n,m,dp);
        return dp[r][c][curr] = min(right,down);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return dfs(0,0,0,grid,n,m,dp);
    }
};