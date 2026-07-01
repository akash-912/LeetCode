class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> safety(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safety[i][j] = 0;
                }
            }
        }
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || safety[nx][ny] != -1)
                    continue;

                safety[nx][ny] = safety[x][y] + 1;
                q.push({nx, ny});
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        pq.push({safety[0][0], 0, 0});
        vis[0][0] = true;

        while (!pq.empty()) {
            auto [safe, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return safe;
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny])
                    continue;
                int newSafe = min(safe, safety[nx][ny]);
                pq.push({newSafe, nx, ny});
                vis[nx][ny] = true;
            }
        }
        return 0;
    }
};