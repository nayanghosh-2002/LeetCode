class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int> prefixArray(n + 2, 0);

        for (auto &i : queries) {
            int l = i[0];
            int r = i[1];
            prefixArray[l] += 1;
            prefixArray[r + 1] -= 1;
        }

        for (int i = 1; i < (int)prefixArray.size(); i++) {
            prefixArray[i] += prefixArray[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (prefixArray[i] < nums[i]) {
                
                return false;
            }
        }

        return true;
    }
};