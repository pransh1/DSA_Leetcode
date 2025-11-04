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
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJoint ds(n * n);

        //Merge all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    for (auto &d : directions) {
                        int nx = i + d[0];
                        int ny = j + d[1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int adjNode = nx * n + ny;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        // after we flip any one 0 to 1 
        int maxIslands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                unordered_set<int> set;
                if(grid[i][j] == 0){
                    for(auto &dir : directions){
                        int nx = i + dir[0];
                        int ny = j + dir[1];
                        if(nx >= 0 && ny >=0 && nx < n && ny < n && grid[nx][ny] == 1){
                            int parent = ds.findUltimateParent(nx*n+ny);
                            set.insert(parent);
                        }
                    }
                }
                int newIsland = 1;
                for(auto &p : set){
                    newIsland += ds.size[p];
                }
                maxIslands = max(newIsland, maxIslands);
            }
        }

        // if no 0 is there
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i/n][j%n] == 1){
                    int parent = ds.findUltimateParent(i*n+j);
                    maxIslands = max(maxIslands, ds.size[parent]);
                }
            }
        }

        return maxIslands;
    }
};