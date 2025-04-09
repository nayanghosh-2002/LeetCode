class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    unordered_set<int> st;

    for (int num : nums) {
        if (num < k) return -1;      // Early exit if any number is less than k
        if (num > k) st.insert(num); // Track unique numbers greater than k
    }

    return st.size(); // Number of operations = number of unique > k
}
};