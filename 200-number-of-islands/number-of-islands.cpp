class DisJoint {
    public:
    vector<int> parent;
    vector<int> size;

    DisJoint(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(parent[node] == node) return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if (parentU == parentV) return;

        if(size[parentU] < size[parentV]){
            size[parentV] += size[parentU];
            parent[parentU] = parentV;
        }
        else {
            size[parentU] += size[parentV];
            parent[parentV] = parentU;
        }
    }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisJoint ds(n * m);
        int totalLand = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] =='1') {
                    totalLand++;
                    int node = i * m + j;
                    for(auto &dir : directions){
                        int ni = i + dir.first;
                        int nj = j + dir.second;

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                            int adjNode = ni * m + nj;

                            int parent1 = ds.findUltimateParent(node);
                            int parent2 = ds.findUltimateParent(adjNode);

                            if(parent1 != parent2) {
                                ds.unionBySize(node, adjNode);
                                totalLand--;
                            }
                        }
                    }
                }
            }
        }
        return totalLand;
    }
};
