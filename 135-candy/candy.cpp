class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();

        vector<int> candies(n, 1);

        // left to right
        for(int i=1; i<n;i++){
            if(r[i] > r[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }

        // right to left
        for(int i=n-2; i>=0;i--) {
            if(r[i] > r[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        int total = 0;
        for(int c: candies) {
            total += c;
        }
        return total;
    }
};