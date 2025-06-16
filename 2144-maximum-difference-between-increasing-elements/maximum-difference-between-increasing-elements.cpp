class Solution {
public:
    int maximumDifference(vector<int>& nums) {
    int n = nums.size(),maxe = nums[n-1],maxd = -1;
    for(int i=n-2;i>=0;i--)
    {
        if(maxe-nums[i]>0) maxd = max(maxd,(maxe-nums[i]));
        else maxe = nums[i];
    }
    return maxd;   
    }
};