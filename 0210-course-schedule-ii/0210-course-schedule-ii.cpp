class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dfsVis,stack<int>& st){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,dfsVis,st)==true) return true;
            }
            else if(dfsVis[it]==1) return true;
        }
        dfsVis[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        stack<int> st;
        vector<int> order;
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);

        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,dfsVis,st)==true) return {};
            }
        }
        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }
};