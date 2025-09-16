class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount + 1, -1);
        int ans = solve(coins, amount);
        return ans >= 1e5 ? -1: ans;
    }

    int solve(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        if(amount < 0) return 1e5;

        if(dp[amount] != -1) return dp[amount];

        int minimumCoin = 1e5;
        for(int coin : coins) {
            int totalCoinUsed = 1 + solve(coins, amount-coin);
            minimumCoin = min(minimumCoin, totalCoinUsed);
        }

        return dp[amount] = minimumCoin;
    }
};