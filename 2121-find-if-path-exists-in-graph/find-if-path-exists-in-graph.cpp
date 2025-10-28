class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(source);
        vis[source] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == destination) {
                return true;
            }
            for(int neighbour : graph[node]) {
                if(!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};