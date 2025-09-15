class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 0);
    }
    int solve(vector<int>& prices, int idx, int buy) {
        // buy
        if(idx >= prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int ans = 0;
        if(buy == 0) {
            int take = -prices[idx] + solve(prices, idx+1, 1);
            int skip = 0 + solve(prices, idx+1, 0); 
            ans = max(take, skip);
        }
        else {
            // sell
            int sell = +prices[idx] + solve(prices, idx+1, 0);
            int dont_sell = 0 + solve(prices, idx+1, 1);
            ans = max(sell, dont_sell);
        }
        return dp[idx][buy] = ans;
    }
};