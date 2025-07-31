class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // res:store all unique OR results from any subarray
        unordered_set<int> res;

        // cur: stores OR results of subarrays ending at the previous index
        unordered_set<int> cur;

        // Iterate over array
        for (int num : arr) {
            unordered_set<int> next;

            // Every new element starts a new subarray by itself
            next.insert(num);

            // Extend all previous subarrays by adding current number
            for (int x : cur) {
                // Take OR with current number and add to the next set
                next.insert(x | num);
            }

            // Update cur to be set of all ORs ending at this position
            cur = next;

            // Add all current ORs to  global result set
            res.insert(cur.begin(), cur.end());
        }

        // size of res gives us number of unique OR results
        return res.size();
    }
};