class Solution {
public:
    // Utility to print DP table (for debugging)
    void printDP(const vector<vector<int>>& dp) {
        for (const auto& row : dp) {
            for (int val : row) cout << val << " ";
            cout << endl;
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Adjacency lists for both trees
        vector<vector<int>> tree1(n), tree2(m);

        for (auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        // DP on tree2 to compute number of reachable nodes within distance i from each node
        vector<vector<int>> dp2(m, vector<int>(k + 1, 0));
        for (int i = 0; i < m; ++i) dp2[i][0] = 1;

        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int neighbor : tree2[node]) {
                if (neighbor == parent) continue;
                dfs2(neighbor, node);
                for (int dist = 1; dist <= k; ++dist) {
                    dp2[node][dist] += dp2[neighbor][dist - 1];
                }
            }
        };

        dfs2(0, -1);

        // Rerooting to propagate counts upwards
        function<void(int, int)> reroot2 = [&](int node, int parent) {
            for (int neighbor : tree2[node]) {
                if (neighbor == parent) continue;
                vector<int>temp = dp2[neighbor];
                for (int dist = 1; dist <= k; ++dist) {
                    int exclude = (dist > 1 ? dp2[neighbor][dist - 2] : 0);
                    int node_contrib = dp2[node][dist - 1] - exclude;
                    temp[dist] += node_contrib;
                }
                dp2[neighbor] = temp;
                reroot2(neighbor, node);
            }
        };

        reroot2(0, -1);

        // Calculate the max reachable nodes in tree2 using up to (k - 1) edges
        int max_reachable_in_tree2 = 0;
        for (int i = 0; i < m; ++i) {
            int reachable = 0;
            for (int dist = 0; dist < k; ++dist) {
                reachable += dp2[i][dist];
            }
            max_reachable_in_tree2 = max(max_reachable_in_tree2, reachable);
        }

        // DP on tree1
        vector<vector<int>> dp1(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; ++i) dp1[i][0] = 1;

        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (int neighbor : tree1[node]) {
                if (neighbor == parent) continue;
                dfs1(neighbor, node);
                for (int dist = 1; dist <= k; ++dist) {
                    dp1[node][dist] += dp1[neighbor][dist - 1];
                }
            }
        };

        dfs1(0, -1);

        // Rerooting for tree1
        function<void(int, int)> reroot1 = [&](int node, int parent) {
            
            for (int neighbor : tree1[node]) {
                if (neighbor == parent) continue;
                vector<int>temp = dp1[neighbor];
                for (int dist = 1; dist <= k; ++dist) {
                    int exclude = (dist > 1 ? dp1[neighbor][dist - 2] : 0);
                    int node_contrib = dp1[node][dist - 1] - exclude;
                    temp[dist] += node_contrib;
                }
                dp1[neighbor] = temp;
                reroot1(neighbor, node);
            }
        };

        reroot1(0, -1);

        // Build result: for each node in tree1, add reachable nodes from tree1 + max reachable from tree2
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int reachable = accumulate(dp1[i].begin(), dp1[i].end(), 0);
            result[i] = reachable + max_reachable_in_tree2;
        }

        return result;
    }
};