class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int minDist = INT_MAX;

        for(int i = 0; i < points.size(); i++) {
            int px = points[i][0];
            int py = points[i][1];

            // check validity
            if(px == x || py == y) {
                int dist = abs(x - px) + abs(y - py);

                if(dist < minDist) {
                    minDist = dist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
