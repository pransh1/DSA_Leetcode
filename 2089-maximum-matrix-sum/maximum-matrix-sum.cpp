class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long total_sum = 0;
        int minAbs = INT_MAX;
        int total_negatives = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                total_sum += abs(matrix[i][j]);

                minAbs = min(minAbs, abs(matrix[i][j]));

                if(matrix[i][j] < 0) {
                    total_negatives++;
                }
            }
        }

        if(total_negatives % 2 == 0) {
            return total_sum;
        }
        else {
            return total_sum - 2LL * minAbs;
        }
    }
};