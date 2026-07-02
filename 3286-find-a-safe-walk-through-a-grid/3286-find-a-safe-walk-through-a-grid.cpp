class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) {
            return (health - grid[0][0]) >= 1;
        }
        vector<vector<int>> max_health(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q;

        int initial_health = health - grid[0][0];
        if (initial_health < 1)
            return false;
        max_health[0][0] = initial_health;
        q.push({0, {0, initial_health}});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second.first;
            int cur_health = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m ) {
                    int next_health = cur_health - grid[nr][nc];
                    if(next_health>=1&&next_health>max_health[nr][nc]){
                        if(nr==n-1&&nc==m-1) return true;

                        max_health[nr][nc] = next_health;
                        q.push({nr,{nc,next_health}});
                    }
                }
            }
        }
        return false;
    }
};