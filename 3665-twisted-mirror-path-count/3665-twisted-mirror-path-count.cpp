class Solution {
public:
    int m, n;
    long long MOD = 1e9 + 7;
    
    // jumpMemo[r][c][dir] stores the encoded destination cell (r * n + c)
    // -2 means uncalculated, -1 means out of bounds (invalid path)
    vector<vector<vector<int>>> jumpMemo;
    vector<vector<int>> dp;
    
    // dir: 0 for RIGHT, 1 for DOWN
    int getDest(int r, int c, int dir, const vector<vector<int>>& grid) {
        // Out of bounds reflection
        if (r < 0 || r >= m || c < 0 || c >= n) return -1; 
        
        // Return cached destination
        if (jumpMemo[r][c][dir] != -2) return jumpMemo[r][c][dir];
        
        // If it's an empty cell, the robot successfully lands here
        if (grid[r][c] == 0) {
            return jumpMemo[r][c][dir] = (r * n + c);
        }
        
        // If it's a mirror, instantly reflect and find the next destination
        if (dir == 0) { 
            // Moving RIGHT into mirror -> reflect DOWN
            return jumpMemo[r][c][dir] = getDest(r + 1, c, 1, grid);
        } else { 
            // Moving DOWN into mirror -> reflect RIGHT
            return jumpMemo[r][c][dir] = getDest(r, c + 1, 0, grid);
        }
    }
    
    int solvePaths(int r, int c, const vector<vector<int>>& grid) {
        // Base Case: Reached the target
        if (r == m - 1 && c == n - 1) return 1;
        
        if (dp[r][c] != -1) return dp[r][c];
        
        long long ways = 0;
        
        // 1. Attempt to move RIGHT (dir = 0)
        int destR = getDest(r, c + 1, 0, grid);
        if (destR != -1) {
            ways = (ways + solvePaths(destR / n, destR % n, grid)) % MOD;
        }
        
        // 2. Attempt to move DOWN (dir = 1)
        int destD = getDest(r + 1, c, 1, grid);
        if (destD != -1) {
            ways = (ways + solvePaths(destD / n, destD % n, grid)) % MOD;
        }
        
        return dp[r][c] = ways;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // If the target itself is a mirror, it reflects the robot before entering, making it unreachable
        if (grid[m - 1][n - 1] == 1) return 0;
        
        // Initialize memoization tables
        jumpMemo.assign(m, vector<vector<int>>(n, vector<int>(2, -2)));
        dp.assign(m, vector<int>(n, -1));
        
        return solvePaths(0, 0, grid);
    }
};