class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, curr = 0, max_len = 0;
        for(int r = 0 ; r < nums.size() ; r++){
            while ((curr & nums[r]) != 0){
                curr ^= nums[l];
                l++;
            }
            curr |= nums[r];
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};