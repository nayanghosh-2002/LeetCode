class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size(), i = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    while (i < n - 2)
    {
        int e1 = nums[i], e2 = nums[i + 1], e3 = nums[i + 2];
        if (e3 - e2 <= k && e3 - e1 <= k && e2 - e1 <= k)
            ans.push_back({e1, e2, e3});
        else
            return {};
        i += 3;
    }
    return ans;    
    }
};