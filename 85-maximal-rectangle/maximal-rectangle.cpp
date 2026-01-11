class Solution {
public:
    int rows, cols;
    vector<vector<int>> memo;

    // Recursive height calculation
    int getHeight(int r, int c, vector<vector<char>>& matrix) {
        if (r < 0) return 0;
        if (memo[r][c] != -1) return memo[r][c];

        if (matrix[r][c] == '0')
            return memo[r][c] = 0;

        return memo[r][c] = 1 + getHeight(r - 1, c, matrix);
    }

    // Largest Rectangle in Histogram using Monotonic Stack
    int largestHistogramArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);  // sentinel

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        memo.assign(rows, vector<int>(cols, -1));

        int ans = 0;

        for (int r = 0; r < rows; r++) {
            vector<int> heights(cols);
            for (int c = 0; c < cols; c++) {
                heights[c] = getHeight(r, c, matrix);
            }
            ans = max(ans, largestHistogramArea(heights));
        }

        return ans;
    }
};
