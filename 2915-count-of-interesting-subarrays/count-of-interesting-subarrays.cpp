typedef long long ll;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        for (auto &x: nums) x %= modulo;
        unordered_map<int, ll> cnt;
        ll ans = 0;
        cnt[0] = 1;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) {
                cur = (cur + 1) % modulo;
            }
            int target = (cur - k + modulo) % modulo;
            ans += cnt[target];
            cnt[cur] += 1;
        }
        return ans;
    }
};