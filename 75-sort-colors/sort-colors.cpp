class Solution {
public:
   void sortColors(vector<int>& nums)
   {
      int count[3] = {0};

     for (int num : nums)
        count[num]++;

     int i = 0;
     for (int n = 0; n < 3; ++n)
        while (count[n]-- > 0)
            nums[i++] = n;
    }
};