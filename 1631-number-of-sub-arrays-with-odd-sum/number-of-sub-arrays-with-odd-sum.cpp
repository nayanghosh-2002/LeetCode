class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int odd = 0, even = 1;
        int prefixSum = 0, res = 0;
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                res = (res + odd) % mod;
                even++; // Current prefix is even
            } else {
                res = (res + even) % mod;
                odd++; // Current prefix is odd
            }
        }
        return res;
    }
};