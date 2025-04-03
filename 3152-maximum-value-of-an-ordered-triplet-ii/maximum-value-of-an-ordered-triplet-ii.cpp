class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();

        int maxval=nums[0];
        int maxdiff=INT_MIN;
        long long triplet=0;

        for(int i=1;i<n-1;i++){
            maxdiff=max(maxdiff,maxval-nums[i]);
            triplet=max(triplet, 1LL * maxdiff * nums[i+1]);
            maxval=max(maxval,nums[i]);
        }

        return triplet;
    }
};