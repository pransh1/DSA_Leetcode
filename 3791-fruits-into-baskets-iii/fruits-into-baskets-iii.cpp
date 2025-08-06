class SegMenTree {
private:
    vector<int> segTree;
    int n;
    void build_tree(vector<int>& nums, int node, int left, int right) {
        if(left==right){
            segTree[node] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        build_tree(nums, 2*node+1, left, mid);
        build_tree(nums, 2*node+2, mid+1, right);
        segTree[node] = max(segTree[2*node+1], segTree[2*node+2]);
    }

    void update(int node, int left, int right, int idx, int val) {
        if(left == right) {
            segTree[node] = val;
            return;
        }
        int mid = (left+right)/2;
        if(idx <= mid) {
            update(2*node+1, left, mid, idx, val);
        }
        else {
            update(2*node+2, mid+1, right, idx, val);
        }
        segTree[node] = max(segTree[2*node+1], segTree[2*node+2]);
    }

    int query(int node, int left, int right, int ql, int qr) {
        if(ql <= left && right <= qr) return segTree[node];
        if(ql > right || qr < left) return -1;
        int mid = left+(right-left) / 2;
        return max(query(2*node+1, left, mid, ql, qr), query(2*node+2, mid+1, right, ql, qr));
    }

public:
    SegMenTree(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        build_tree(nums, 0, 0, n-1);
    }

    void updateRange(int idx, int val){
        update(0, 0, n-1, idx, val);
    }

    int q_max(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegMenTree segTree(baskets);
        int unplaced = 0;
        for(auto& fruit : fruits) {
            if(segTree.q_max(0, baskets.size()-1) < fruit) {
                unplaced++;
            }
            else {
                int l = 0;
                int r = baskets.size()-1;
                while(l<r) {
                    int mid = (l+r)/2;
                    if(segTree.q_max(l, mid) < fruit) l = mid+1;
                    else r = mid;
                }
                segTree.updateRange(l, 0);
            }
        }
        return unplaced;
    }
};