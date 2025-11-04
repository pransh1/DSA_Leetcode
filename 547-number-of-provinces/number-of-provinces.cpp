class DisJoint {
public:
    vector<int> parent;
    vector<int> size;

    DisJoint(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if (parentU == parentV) return;

        if (size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        } else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJoint ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    ds.unionBySize(i, j);
            }
        }

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(ds.findUltimateParent(i));
        }

        return st.size();
    }
};
