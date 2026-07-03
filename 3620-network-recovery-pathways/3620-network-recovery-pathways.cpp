class Solution {
public:
    bool bfs(vector<vector<pair<int,int>>>& adj,vector<bool>& online, long long k,int cost){
        queue<pair<int,long long>> q;
        int n = online.size();
        vector<long long> minCost(n, LLONG_MAX);
        minCost[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().first;
            long long totalCost = q.front().second;
            q.pop();
            if(totalCost > minCost[node]) continue;
            if(node==n-1) return true;
            for(auto it: adj[node]){
                int next_node = it.first;
                int weight = it.second;
                long long newCost = totalCost + (long long)weight;
                if(totalCost+(long long)weight>k||online[next_node]==false){
                    continue;
                }
                if(weight>=cost&&newCost<minCost[next_node]){
                    q.push({next_node,totalCost+weight});
                    minCost[next_node] = newCost;
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int low = INT_MAX;
        int high = INT_MIN;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            low = min(low,w);
            high = max(high,w);
        }
        if(!bfs(adj,online,k,low)) return -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(bfs(adj,online,k,mid)){
                low = mid + 1;
            }else   high = mid - 1;
        }
        return high;
    }
};