class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{0,-1}, {1,0}, {0,1}};
    int n, m;
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis) {
        vis[x][y] = 1;
        int side = 4;
        int total = 0;
        for(auto& d : directions) {
            int nx = x + d[0];
            int ny = y + d[1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                side -= 1;
                if(!vis[nx][ny]) {
                    total += dfs(grid, nx, ny, vis);
                }
            }       
        }
        return side + total;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int perimeter=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    perimeter += dfs(grid, i, j, vis);
                }
            }
        }
        return perimeter;
    }
};