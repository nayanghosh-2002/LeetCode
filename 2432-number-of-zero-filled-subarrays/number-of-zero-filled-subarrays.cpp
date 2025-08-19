class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(!nums[i]){
                cnt += 1;
                ans += cnt;
            }
            else cnt = 0;
        }

        return ans;
    }
};