class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for(auto& dir : dirs) {
                            int nx = x + dir[0];
                            int my = y + dir[1];

                            if(nx >= 0 && nx < n && my >=0 && my < m && grid[nx][my] == '1') {
                                grid[nx][my] = '0';
                                q.push({nx,my});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};