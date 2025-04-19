#define ll long long
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll cnt=0;
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            ll idx1=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            ll idx2=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin()-1;
            cnt=cnt+max(0ll,idx2-idx1+1);
        }
        return cnt;
    }
};