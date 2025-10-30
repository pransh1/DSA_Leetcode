class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, (vector<int>(m, 0)));
        queue<pair<int, int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    break;
                }
            }
        }

        if(q.empty()) return 0;

        int perimeter = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int side = 4;

            for(auto& d : directions) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    side -= 1;
                    if(!vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }

                }
            }
            perimeter += side;
        }
        return perimeter;
    }
};