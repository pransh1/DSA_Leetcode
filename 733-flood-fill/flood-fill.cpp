class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int startColor = image[sr][sc];
        // if given index color is equal to given color return images directly 
        if(startColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        // if not then first convert the starting val to given color
        image[sr][sc] = color;

        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();

            for(auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == startColor) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};