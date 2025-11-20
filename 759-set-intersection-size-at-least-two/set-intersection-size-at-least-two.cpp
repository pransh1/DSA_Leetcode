class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end ASC, and if tie, start DESC
        sort(intervals.begin(), intervals.end(),
             [&](const auto &a, const auto &b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
        });

        // a -> smallest chosen 
        // b -> largest chosen
        // so we always have to maintain a < b
        int a = -1, b = -1;
        int ans = 0;
        for(auto& it: intervals) {
            int s = it[0], e = it[1];   
            // b < s
            // we can take two numbers 
            // so add +2 with ans

            if(b<s) {
                ans += 2;
                a = e-1;
                b = e;
            }

            // if a < s 
            // means we already have one elem we need just one more
            if(a < s ) {
                ans += 1;
                a = b;
                b = e;
            }
            // else already satisfied no need to take any
        }   

        return ans;

    }
}; 