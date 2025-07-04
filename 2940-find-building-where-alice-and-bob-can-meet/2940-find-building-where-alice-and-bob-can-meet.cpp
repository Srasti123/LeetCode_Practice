class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(const vector<int>& heights) {
        n = heights.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, heights);
    }
    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * node, l, m, a);
            build(2 * node + 1, m + 1, r, a);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    int rangeMax(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return -1e9;
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        return max(
            rangeMax(2 * node, l, m, ql, qr),
            rangeMax(2 * node + 1, m + 1, r, ql, qr)
        );
    }
    // For optional height increase updates
    void rangeAdd(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int m = (l + r) / 2;
        rangeAdd(2 * node, l, m, ql, qr, val);
        rangeAdd(2 * node + 1, m + 1, r, ql, qr, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    // Binary search on segment tree to find leftmost index
    int findFirstGreater(int node, int l, int r, int ql, int qr, int target) {
        push(node, l, r);
        if (qr < l || r < ql || tree[node] <= target) return -1;
        if (l == r) return l;
        int m = (l + r) / 2;
        int left = findFirstGreater(2 * node, l, m, ql, qr, target);
        if (left != -1) return left;
        return findFirstGreater(2 * node + 1, m + 1, r, ql, qr, target);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree st(heights);
        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int h1 = heights[a], h2 = heights[b];
            if (a == b) {
                ans.push_back(a);
            } else if (a < b && h1 < h2) {
                ans.push_back(b);
            } else if (b < a && h2 < h1) {
                ans.push_back(a);
            } else {
                int l = max(a, b) + 1;
                if (l >= n) {
                    ans.push_back(-1);
                    continue;
                }
                int max_h = max(h1, h2);
                int idx = st.findFirstGreater(1, 0, n - 1, l, n - 1, max_h);
                ans.push_back(idx);
            }
        }
        return ans;
    }
};