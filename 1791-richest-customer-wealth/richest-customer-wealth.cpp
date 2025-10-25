class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        // as you know its a 2d vector so in this for loop we are accessing the inner vector
        /*
            ex ->
            [         jt 
                       |             
                it -> [1, 2, 3],
                [3, 2, 1]
            ]
            here through this for loop we are accessing inner vector
        */
        for(auto it = accounts.begin(); it != accounts.end(); it++) {
            
            int sum = 0;

            for(auto jt = it->begin(); jt != it->end(); jt++) {
                // and through this loop we are accessing the vals of it
                sum += *jt;
            }

            if (sum > ans) {
                ans = sum;
            }
        }
        return ans;
    }
};