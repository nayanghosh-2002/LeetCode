class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = abs(nums[n - 1] - nums[0]);

        for (int i = 1; i < n; i++) {
            int maxhere = abs(nums[i] - nums[i - 1]);
            if (maxhere > maxi) {
                maxi = maxhere;
            }
        }
        return maxi;
    }
};