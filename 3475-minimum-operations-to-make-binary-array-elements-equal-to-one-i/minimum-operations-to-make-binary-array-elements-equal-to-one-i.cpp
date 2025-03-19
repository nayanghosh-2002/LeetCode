class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0; i+2<n; i++){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i+1] ^= 1; // 0^1=1,  1^1=0
                nums[i+2] ^= 1;
                cnt++;
            }
        }
        for(int i=0; i<n; i++){ // check if it contains all 1's , if it contain 0 then return -1;
            if(nums[i] == 0){
                return -1;
            }
        }
        return cnt;
    }
};