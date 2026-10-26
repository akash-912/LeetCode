class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_count = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
                else if(grid[i][j]==1) fresh_count++;
            }
        }
        int time = 0;
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                int nt = t + 1;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    q.push({{nr,nc},nt});
                    fresh_count--;
                }
            }
        }
        return fresh_count==0? time: -1;
    }
};