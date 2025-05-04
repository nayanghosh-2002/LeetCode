class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, unordered_map<int, int>> mp;
        int ans = 0;
        for(auto vec:dominoes) {
            int u = vec[0];
            int v = vec[1];
            if(v < u) swap(u, v);
            mp[u][v]++;
            ans += mp[u][v]-1;
        }

        return ans;
    }
};