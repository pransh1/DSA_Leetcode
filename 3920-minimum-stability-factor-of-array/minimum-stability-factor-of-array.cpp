class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }
    int merge(int leftVal, int rightVal) {
        return __gcd(leftVal, rightVal);
    }

    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r) return tree[v];
        int tm = (tl + tr) / 2;
        int left = query(v * 2, tl, tm, l, min(r, tm));
        int right  = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return merge(left,right );

    }

    int getGCD(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> a;
    int n, maxC;

    bool canBreak(int maxLen, SegmentTree& seg) {
        int changes = 0, l = 0;

        for (int r = 0; r < n; r++) {
            int g = seg.getGCD(l, r);

            while (l + 1 <= r && g == 1) {
                l++;
                g = seg.getGCD(l, r);
            }

            if (r - l + 1 > maxLen) {
                l = r + 1;
                changes++;
            }
        }
        return changes <= maxC;
    }

    int minStable(vector<int>& nums, int _maxC) {
        a = nums;
        n = a.size();
        maxC = _maxC;

        if (count(a.begin(), a.end(), 1) + maxC >= n) return 0;

        SegmentTree seg(a);
        int l = 0, r = n + 1;

        while (r > l + 1) {
            int mid = (l + r) / 2;
            if (canBreak(mid, seg)) r = mid;
            else l = mid;
        }
        return r;
    }
};