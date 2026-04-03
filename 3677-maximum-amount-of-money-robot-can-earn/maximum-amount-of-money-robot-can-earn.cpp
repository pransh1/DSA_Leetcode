// class Solution {
// public:
//     int n, m;
//     vector<vector<vector<int>>> dp;

//     int solve(int i, int j, int k, vector<vector<int>>& coins) {
//         // out of bounds
//         if(i >= n || j >= m) return INT_MIN;

//         // base case
//         if(i == n-1 && j == m-1) {
//             if(coins[i][j] >= 0) return coins[i][j];

//             // negative cell
//             if(k > 0) return 0; // neutralize
//             return coins[i][j]; // take loss
//         }

//         if(dp[i][j][k] != -1) return dp[i][j][k];

//         int ans = INT_MIN;

//         if(coins[i][j] >= 0) {
//             int val = coins[i][j];
//             int right = solve(i, j+1, k, coins);
//             int down  = solve(i+1, j, k, coins);

//             ans = val + max(right, down);
//         } 
//         else {
//             // option 1: take loss
//             int take = coins[i][j] + max(
//                 solve(i, j+1, k, coins),
//                 solve(i+1, j, k, coins)
//             );

//             // option 2: neutralize
//             int neutralize = INT_MIN;
//             if(k > 0) {
//                 neutralize = max(
//                     solve(i, j+1, k-1, coins),
//                     solve(i+1, j, k-1, coins)
//                 );
//             }

//             ans = max(take, neutralize);
//         }

//         return dp[i][j][k] = ans;
//     }

//     int maximumAmount(vector<vector<int>>& coins) {
//         n = coins.size();
//         m = coins[0].size();

//         dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, -1)));

//         return solve(0, 0, 2, coins);
//     }
// };

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        // dp[i][j][k] → max coins from (i,j) with k neutralizations left
        vector dp(n, vector(m, vector<int>(3, INT_MIN)));

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                for(int k = 0; k <= 2; k++) {

                    // last cell
                    if(i == n-1 && j == m-1) {
                        if(coins[i][j] >= 0) dp[i][j][k] = coins[i][j];
                        else {
                            if(k > 0) dp[i][j][k] = 0;
                            else dp[i][j][k] = coins[i][j];
                        }
                        continue;
                    }

                    int best = INT_MIN;

                    // move right
                    if(j+1 < m) best = max(best, dp[i][j+1][k]);

                    // move down
                    if(i+1 < n) best = max(best, dp[i+1][j][k]);

                    // if no valid path
                    if(best == INT_MIN) continue;

                    // positive cell
                    if(coins[i][j] >= 0) {
                        dp[i][j][k] = coins[i][j] + best;
                    }
                    else {
                        // option 1: take loss
                        int take = coins[i][j] + best;

                        // option 2: neutralize
                        int neutralize = INT_MIN;
                        if(k > 0) {
                            int best2 = INT_MIN;

                            if(j+1 < m) best2 = max(best2, dp[i][j+1][k-1]);
                            if(i+1 < n) best2 = max(best2, dp[i+1][j][k-1]);

                            neutralize = best2;
                        }

                        dp[i][j][k] = max(take, neutralize);
                    }
                }
            }
        }

        return dp[0][0][2];
    }
};