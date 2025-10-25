class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);

        int maxi = INT_MIN;

        for(int i=0;i<n;i++) {
            if(candies[i] > maxi) {
                maxi = candies[i];
            }
        }    

        for(int i=0;i<n;i++) {
            int candy = candies[i] + extraCandies;
            if(candy >= maxi) {
                ans[i] = true;
            }
            else {
                ans[i] = false;
            }
        }
        return ans;
    }
};