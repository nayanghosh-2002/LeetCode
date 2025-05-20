class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        // prefixArray[i] will count how many queries cover index i
        // we size it n+2 so that prefixArray[r+1] is always valid
        vector<int> prefixArray(n + 2, 0);

        // 1) Build the “difference array”:
        //    For each query [l, r], we do:
        //      prefixArray[l] += 1
        //      prefixArray[r+1] -= 1
        //    which marks +1 to the coverage over [l..r] in O(1) per query.
        for (auto &i : queries) {
            int l = i[0];
            int r = i[1];
            prefixArray[l] += 1;
            prefixArray[r + 1] -= 1;
        }

        // 2) Turn the difference array into the actual coverage counts
        //    by taking a prefix sum over prefixArray.
        //    After this loop, prefixArray[i] == number of queries covering i.
        for (int i = 1; i < (int)prefixArray.size(); i++) {
            prefixArray[i] += prefixArray[i - 1];
        }

        // 3) Check feasibility:
        //    At index i we need at least nums[i] covering queries in order
        //    to decrement nums[i] all the way to zero.
        for (int i = 0; i < n; i++) {
            if (prefixArray[i] < nums[i]) {
                // Not enough query-coverage at i
                return false;
            }
        }

        // If every position had enough coverage, it’s possible
        return true;
    }
};