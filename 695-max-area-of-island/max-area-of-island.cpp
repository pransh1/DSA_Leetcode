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

    void unionBySize(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);
        
        if(parentV == parentU) return;

        if(size[parentU] < size[parentV]) {
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
    vector<vector<int>> directions = {{-1, 0}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        DisJoint ds(m*n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int node = i*n+j;

                    for(auto &dir : directions) {
                        int nx = i + dir[0];
                        int ny = j + dir[1];

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
                        int adjNode = nx * n + ny;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int maxTotal = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1){
                    int parent = ds.findUltimateParent(i*n+j);
                    maxTotal = max(maxTotal, ds.size[parent]);

                }
            }
        }

        return maxTotal;
    }
};