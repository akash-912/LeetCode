class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& edge:roads){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        int minScore = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                int next_node = it.first;
                int w = it.second;
                minScore = min(minScore,w);
                if(vis[next_node]==0){
                    vis[next_node] = 1;
                    q.push(next_node);
                }
            }
        }
        return minScore;
    }
};