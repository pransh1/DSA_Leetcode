class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;

        vector<vector<int>> conglictingPoints(n+1);
        // conglictingPoints[i] = {points which conflict with i}
        for(auto& p : conflictingPairs){
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);

            conglictingPoints[b].push_back(a); // {1,2,a,,,b}
        }

        int maxConflict = 0;
        int secondMaxConflict = 0;
        vector<long long> extra(n+1, 0);
        // extra[i] = number of extra subarrays by removing the conglictingPoints[i];
        for(int end = 1; end<=n; end++) { // visiting each point and treating them as subarray ending at this point
            // total subarrays ending at this point 'end'
            for(int &u : conglictingPoints[end]) { // check all conflicting points of end
                if(u >= maxConflict) {
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                }
                else if(u > secondMaxConflict) {
                    secondMaxConflict = u;
                } 
            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }

        return valid + *max_element(begin(extra), end(extra));
    }
};