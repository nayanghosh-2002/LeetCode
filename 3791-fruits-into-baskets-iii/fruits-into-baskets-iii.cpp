class SegTree {
public:
    vector<int> tree;
    int size;
    SegTree(int n) : size(n) { tree.assign(4 * n + 1, 0); }
    void b(vector<int>& a, int start, int end, int node) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        b(a, start, mid, 2 * node);
        b(a, mid + 1, end, 2 * node + 1);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        return;
    }
    void u(int start, int end, int idx, int delta, int node) {
        if (start == end) {
            tree[node] = delta;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            u(start, mid, idx, delta, 2 * node);
        } else {
            u(mid + 1, end, idx, delta, 2 * node + 1);
        }
        tree[node] = min(tree[2 * node + 1], tree[2*node]);
        return;
    }
    int q(int start, int end, int l, int r, int node) {
        if (l <= start && end <= r)
            return tree[node];
        if (start > r || end < l)
            return INT_MAX;
        int mid = (start + end) / 2;
        return min(q(start, mid, l, r, 2 * node),
                   q(mid + 1, end, l, r, 2 * node + 1));
    }
    void build(vector<int>& a) {
        b(a, 0, size - 1, 1);
        return;
    }
    void update(int idx, int delta) {
        u(0, size - 1, idx, delta, 1);
        return;
    }
    int query(int l, int r) { return q(0, size - 1, l, r, 1); }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegTree seg(n);
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            b.emplace_back(baskets[i], i);
        }
        sort(b.begin(), b.end());
        sort(baskets.begin(), baskets.end());
        vector<int> id;
        vector<int> hash_id(n);
        for (auto it : b)
            id.push_back(it.second);
        for (int i = 0; i < n; i++) {
            hash_id[id[i]] = i;
        }

        seg.build(id);

        int ans = n;
        for (int i = 0; i < n; i++) {
            int index = lower_bound(baskets.begin(), baskets.end(), fruits[i]) -
                        baskets.begin();
         
            if (index >= n) {
                continue;
            }
            int mn = seg.query(index, n - 1);      
            if (mn < n) {
                ans--;
                seg.update(hash_id[mn], INT_MAX);
            }
        }
        return ans;
    }
};