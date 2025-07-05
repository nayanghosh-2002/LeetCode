class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;

        // Create a frequency array of size 501 (1-based index, since arr[i] <= 500)
        vector<int> nums(501, 0);

        // Count the frequency of each number
        for (int i = 0; i < arr.size(); i++) {
            nums[arr[i]] += 1;
        }

        // Check for lucky numbers: value == frequency
        for (int i = 1; i < 501; i++) {
            if (nums[i] == i) {
                ans = i; // Update answer if found
            }
        }

        return ans;
    }
};