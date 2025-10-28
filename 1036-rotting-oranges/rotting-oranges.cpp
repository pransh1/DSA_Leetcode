class Solution {
public:
    vector<vector<int>> directions{{-1,0}, {0,-1}, {1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int time = 0;
        int fresh = 0;

        // first count all fresh oranges and push all 2 in queue
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // // if no fresh then return 0
        if(fresh == 0) return 0;
        // now we have to count how much time (level) does it take to convert all fresh oranges to
        // rotten oranges
        while(!q.empty()) {
            int size = q.size();
            // bool changed = false;
            for(int k = 0; k<size; k++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1) {
                        continue;
                    }
                    // convert it to 2
                    grid[nx][ny] = 2;
                    fresh--;
                    // changed = true;
                    q.push({nx, ny});
                }
            }
            // if(changed) time++;
            time++;
        }
        return fresh == 0 ? time - 1 : -1;
    }
};