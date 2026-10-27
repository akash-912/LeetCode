class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,dfsVis)==true) return true;
            }
            else if(dfsVis[it]==1) return true;
        }
        dfsVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,dfsVis)==true) return false;
            }
        }
        return true;
    }
};