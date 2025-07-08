class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<int> f(k + 1, -1);
        f[0] = 0;
        sort(events.begin(), events.end());
        map<int, vector<pair<int, int>>> Map;
        int cur = 0;
        for (auto &x: events) {
            while (Map.size() > 0 && (*Map.begin()).first < x[0]) {
                vector<pair<int, int>> tmp = (*Map.begin()).second;
                for (auto &y: tmp) f[y.first] = max(f[y.first], y.second);
                Map.erase((*Map.begin()).first);
            }
            for (int i = 0; i < k; i++) {
                if (f[i] == -1) break;
                Map[x[1]].push_back({i + 1, f[i] + x[2]});
            }
        }
        while (Map.size() > 0) {
            vector<pair<int, int>> tmp = (*Map.begin()).second;
            for (auto &y: tmp) f[y.first] = max(f[y.first], y.second);
            Map.erase((*Map.begin()).first);
        }
        int ans = 0;
        for (auto &x: f) ans = max(ans, x);
        return ans;
    }
};