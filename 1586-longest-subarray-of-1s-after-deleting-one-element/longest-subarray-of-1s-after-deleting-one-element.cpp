class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int zero=0;
        int s=0;
        int e=0;
        int mx=0;
        
        while(e<nums.size()){
           if(!nums[e]) zero++;
           while(zero>1 && s<e){
               if(!nums[s]) zero--;
               s++;
           }
           mx=max(mx,e-s);
           e++;
        }
        return mx;
    }
};