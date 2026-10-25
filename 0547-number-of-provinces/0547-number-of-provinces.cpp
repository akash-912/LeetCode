class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 0;
        for(auto it:adj[node]){
            if(vis[it]==-1){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int connected = 0;
        vector<int> vis(n,-1);
        for(int i = 0;i<n;i++){
            if(vis[i]==-1){
                dfs(i,vis,adj);
                connected++;
            }
        }
        return connected;
    }
};