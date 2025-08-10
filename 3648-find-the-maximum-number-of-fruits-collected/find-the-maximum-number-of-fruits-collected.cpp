class Solution {
public:
    int n;
    vector<vector<int>> t;
    int child1Collect(vector<vector<int>>& fruits) {
        int count = 0;
        for(int i=0;i<n; i++) {
            count += fruits[i][i];
        }
        return count;
    }

    int child2Collect(int i, int j, vector<vector<int>>& fruits) {
        if(i >= n || j < 0 || j >= n) return 0;
        if(i==n-1 && j==n-1) return 0;
        if(i==j || i>j) return 0;
        if(t[i][j] != -1) return t[i][j];
        int bottomLeft  = fruits[i][j] + child2Collect(i+1, j-1, fruits);
        int bottomDown  = fruits[i][j] + child2Collect(i+1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collect(i+1, j+1, fruits);
        return t[i][j] = max({bottomLeft, bottomDown, bottomRight});
    }

    int child3Collect(int i, int j, vector<vector<int>>& fruits) {
        if(i >= n || i < 0 || j >= n) return 0;
        if(i==n-1 && j==n-1) return 0;
        if(i==j || i<j) return 0;
        if(t[i][j] != -1) return t[i][j];
        int upRight  = fruits[i][j] + child3Collect(i-1, j+1, fruits);
        int right  = fruits[i][j] + child3Collect(i, j+1, fruits);
        int bottomRight = fruits[i][j] + child3Collect(i+1, j+1, fruits);
        return t[i][j] = max({upRight, right, bottomRight});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        t.resize(n, vector<int>(n, -1));
        int child_1 = child1Collect(fruits);
        int child_2 = child2Collect(0, n-1, fruits);
        int child_3 = child3Collect(n-1, 0, fruits);
        
        return child_1 + child_2 + child_3;
    }
};