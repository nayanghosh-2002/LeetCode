class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        for (int val = 0; val < k; ++val) {
            vector<int> dp(k, 0);  // dp[i] = max length ending with mod i
            for (int x : nums) {
                int mod = x % k;
                int required_prev_mod = (val - mod + k) % k;
                dp[mod] = max(dp[mod], dp[required_prev_mod] + 1);
                ans = max(ans, dp[mod]);
            }
        }

        return ans;
    }
};