class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0;
        vector<int> dif(nums.size()-1);
        for(int i=0;i<nums.size()-1;i++)
        {
            dif[i] = (nums[i+1]-nums[i] > 0 ? 1 : nums[i+1]-nums[i]<0 ? -1 : 0);
        }
        int i=0;
        while(i<dif.size() && dif[i] == 0)
        {
            i++;
        }
        int cur = dif[i];
        i++;
        while(i<dif.size())
        {
            if(dif[i]==0)
            {
                i++;
                
            }
            else if(dif[i] != cur)
            {
                cnt++;
                cur = dif[i];
                i++;
            }
            else
                i++;
        }
        return cnt;
    }
};