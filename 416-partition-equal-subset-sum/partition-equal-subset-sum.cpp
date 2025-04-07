class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
    int sum =0;
    for(int i : nums){
        sum +=i;
    }
    if(sum%2 != 0){
        return false;
    }
    sum /=2;
    std::bitset<10000> dp;
    dp[0] = 1;
    for(auto i : nums){
        dp |= (dp <<i);
    }


    return dp[sum];
}
};
