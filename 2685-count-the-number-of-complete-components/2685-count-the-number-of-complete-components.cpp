class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& visited,int node, int& edges,int& vertices){
        visited[node] = 1;
        vertices++;
        edges += adj[node].size();
        for(auto& it: adj[node]){
            if(visited[it]==0){
                dfs(adj,visited,it,edges,vertices);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }    
        vector<int> visited(n,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(visited[i]==0){
                int edgesCount = 0;
                int verticesCount = 0;
                dfs(adj,visited,i,edgesCount, verticesCount);

                int val = ((verticesCount)*(verticesCount-1));
                if(edgesCount==val){
                    ans++;
                }
            }
        }
        return ans;
    }
};