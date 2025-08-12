class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;
        for(int i=0;i<=n; i++) {
            int currH = (i==n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > currH) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxi = max(maxi, height*width);
            }
            st.push(i);
        }
        return maxi;
    }
};