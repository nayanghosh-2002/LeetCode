class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> lastSeen(32, 0), res(n);
        for(int i = n - 1; i >= 0; i--) {
            int maxRange = i;
            for(int bit = 0; bit < 32; bit++) {
                if(nums[i] & (1 << bit))
                    lastSeen[bit] = i;
                maxRange = max(maxRange, lastSeen[bit]);
            }
            res[i] = maxRange - i + 1;
        }

        return res;
    }
};