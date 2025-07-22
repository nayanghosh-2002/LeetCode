class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        long long max_sum=0;
        unordered_map<int,int> mp;
        long long sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(mp.find(nums[i])!=mp.end()){
                sum-=nums[j];
                mp.erase(nums[j]);
                j++;
            }
            mp[nums[i]]=1;
            sum+=nums[i];
            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};