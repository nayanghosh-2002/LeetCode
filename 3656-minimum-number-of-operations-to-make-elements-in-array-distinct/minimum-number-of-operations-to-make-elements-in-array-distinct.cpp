class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bitset<101> bits;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(bits[nums[i]]==1)
                return (i+3)/3;
            bits[nums[i]]=1;
        }
        return 0;
    }
};