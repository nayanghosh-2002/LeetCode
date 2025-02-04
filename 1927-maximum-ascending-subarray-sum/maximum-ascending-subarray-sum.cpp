class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                res = max(res, sum);
                sum = nums[i];
            }
        }
        return max(res, sum);
    }
};