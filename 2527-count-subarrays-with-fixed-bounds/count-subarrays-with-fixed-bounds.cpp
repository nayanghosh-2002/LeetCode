class Solution {
public:
    long long f(vector<int> &nums, int minK, int maxK, int l, int r){
        int i = l, j = l, minCnt = 0, maxCnt = 0;
        long long cnt = 0;
        while(j < r){
            if(nums[j] == minK)
                minCnt++;
            if(nums[j] == maxK)
                maxCnt++;
            while(minCnt and maxCnt){
                cnt += r - j;
                if(nums[i] == minK)
                    minCnt--;
                if(nums[i] == maxK)
                    maxCnt--;
                i++;
            }
            j++;
        }
        return cnt;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;
        int l = 0, r = 0, n = nums.size();
        while(r < n){
            if(nums[r] > maxK or nums[r] < minK){
                cnt += f(nums, minK, maxK, l, r);
                r++;
                l = r;
            }
            else
                r++;
        }
        if(l != r)
            cnt += f(nums, minK, maxK, l, r);
        return cnt;
    }
};