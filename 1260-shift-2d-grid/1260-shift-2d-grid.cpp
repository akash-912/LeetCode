class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int m = grid.size();
        while(k--){
            int store = grid[m-1][n-1];
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    int prev = store;
                    store = grid[i][j];
                    grid[i][j] = prev;
                }
            }
        }
        return grid;
    }
};