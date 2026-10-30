#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build the adjacency list: adj[u] = {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[node][count] = minimum cost to reach `node` ending with `count` consecutive chars
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        // Priority queue stores {cost, current_node, consecutive_count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Start at node 0. The first character is labels[0], so consecutive count is 1.
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            // If we reach the target node, we can return the distance immediately 
            // since Dijkstra guarantees it's the shortest path.
            if (u == n - 1) return d;

            // Skip outdated states
            if (d > dist[u][count]) continue;

            // Traverse neighbors
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                // Determine the new consecutive character count
                int new_count = (labels[u] == labels[v]) ? count + 1 : 1;

                // Only proceed if we haven't exceeded the consecutive limit k
                if (new_count <= k) {
                    int new_d = d + w;
                    // Relaxation step
                    if (new_d < dist[v][new_count]) {
                        dist[v][new_count] = new_d;
                        pq.push({new_d, v, new_count});
                    }
                }
            }
        }

        return -1; // No valid path found
    }
};