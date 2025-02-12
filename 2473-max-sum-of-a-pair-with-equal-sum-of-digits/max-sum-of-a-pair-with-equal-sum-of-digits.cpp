class Solution {
public:
    int sumDigits(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> sums;
        int res = -1;
        
        for (auto num : nums) {
            int digits = sumDigits(num);
            if (sums.count(digits)) res = max(res, num + sums[digits]);
            sums[digits] = max(sums[digits], num);
        }

        return res;
    }
};