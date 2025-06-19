class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        int left = 0;
        int n = nums.size();
        while(left < n){
            int right = left;
            int Min = nums[left];
            int Max = nums[right];
            
            while(right < n && nums[right] - Min <= k){
                Max = max(nums[right] , Max);
                right++;
            }
            ans++;
            left = right;
        }
        return ans;
    }
};