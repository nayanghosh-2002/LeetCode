class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPair = (n * (n - 1) / 2);
        long long cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x = nums[i] - i;
            if (mp.find(x) != mp.end()) {
                cnt += mp[x];
            }
            mp[x]++;
        }
        return totalPair - cnt;
    }
};