class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xor_sum = 0;

        for (int i = 0; i < nums.size(); i++){
            xor_sum |= nums[i];
        }

        return xor_sum * (1 << (nums.size() - 1));
    }
};