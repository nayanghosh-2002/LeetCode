class Solution {
private:
    bool check(vector<int>& nums, int p, int mid) {
        int n = nums.size();
        for (int i = 0; i + 1 < n;) {
            if (nums[i + 1] - nums[i] <= mid) {
                p--;
                i += 2; // take this pair
                if (p <= 0)return true;
            } else {
                i++; // move to next
            }
        }
        return p <= 0;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)return 0;
        sort(nums.begin(), nums.end());

        int start = 0, end = 1e9;
        int mid = start + (end - start) / 2;
        int ans = -1;

        while (start <= end) {
            if (check(nums, p, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};