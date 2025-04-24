class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int arr[2001];
        int arr_s[2001];
        for(int i = 0; i < 2001; i++) 
        {
            arr[i] = 0;
            arr_s[i] = 0;
        }
        int left = 0;
        int count = 0;
        int countS = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (arr[nums[i]] == 0) count++;
            arr[nums[i]]++;
        }
        int res = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (arr_s[nums[right]] == 0) countS++;
            arr_s[nums[right]]++;
            if (countS == count)
            {
                while (countS == count && left <= right)
                {
                    res += (nums.size() - right);
                    arr_s[nums[left]]--;
                    if (arr_s[nums[left]] == 0) countS--;
                    left++;
                }
            }
        }
        return res;
    }
};