// class SegMenTree {
// private:
//     int n;
//     vector<int> segTree;

//     void build_tree(vector<int>& nums, int node, int left, int right) {
//         if(left == right) {
//             segTree[node] = nums[left];
//             return;
//         }
//         int mid = left+(right-left)/2;
//         build_tree(nums, 2*node+1, left, mid);
//         build_tree(nums, 2*node+2, mid+1, right);
//         segTree[node] = max(segTree[2*node+1], segTree[2*node+2]);
//     }

//     void update_tree(int node, int left, int right, int idx, int val) {
//         if(left==right) {
//             segTree[node] = val;
//             return;
//         }
//         int mid = left+(right-left)/2;
//         if(idx <= mid) {
//             update_tree(2*node+1, left, mid, idx, val);
//         }
//         else update_tree(2*node+2, mid+1, right, idx, val);
//         segTree[node] = max(segTree[2*node+1], segTree[2*node+2]);
//     }

//     int getMax(int node, int left, int right, int ql, int qr) {
//         if(ql <= left && right <= qr) return segTree[node];
//         if(ql > right || qr < left) return -1;
//         int mid = left+(right-left) / 2;
//         return max(getMax(2*node+1, left, mid, ql, qr), getMax(2*node+2, mid+1, right, ql, qr));
//     }
// public:
//     SegMenTree(vector<int>& nums) {
//         n = nums.size();
//         segTree.resize(4*n);
//         build_tree(nums, 0, 0, n-1);
//     }
//     void update(int idx, int val) {
//         update_tree(0, 0, n-1, idx, val);
//     }

//     int Max(int left, int right){
//         return getMax(0, 0, n-1, left, right);
//     }
// };

// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         SegMenTree segTree(baskets);
//         int unPlaced = 0;
//         int n = baskets.size();
//         for(auto &fruit : fruits) {
//             if(segTree.Max(0, n-1) < fruit) {
//                 unPlaced++;
//             }
//             else {
//                 int l = 0;
//                 int r = n-1;
//                 while(l<r) {
//                     int mid = l+(r-l)/2;
//                     if(segTree.Max(l, mid) < fruit) {
//                         l = mid+1;
//                     }
//                     else r = mid;
//                 }
//                 segTree.update(l, 0);
//             }
//         }
//         return unPlaced;
//     }
// };

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        vector<bool> used(m, false);
        int unplaced = 0;
        for(int i=0;i<n;i++) {
            bool vis = false;
            for(int j=0;j<m;j++) {
                if(!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    vis = true;
                    break;
                }
            }
            if(!vis) unplaced++;
        }
        return unplaced;
    }
};