class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long zero1 = 0;

        // Calculate sum and count of zeros in nums1
        for (auto i : nums1) {
            sum1 += i;
            if (i == 0) zero1++;
        }

        long long sum2 = 0;
        long long zero2 = 0;

        // Calculate sum and count of zeros in nums2
        for (auto i : nums2) {
            sum2 += i;
            if (i == 0) zero2++;
        }

        // If sums are already equal
        if (sum1 == sum2) {
            if (sum1 == 0) {
                // Both arrays are full of zeros
                if (zero1 == zero2) return zero1;
            }

            // Return current sum if zero counts match
            if (zero1 == zero2) {
                return sum1;
            } else {
                // One array has more zeros
                if (zero1 == 0 || zero2 == 0) {
                    return -1;
                }
                return sum1 + max(zero1, zero2);
            }
        } else {
            // When sums are different
            if (sum1 > sum2) {
                // Try to increase sum2 using its zeros
                if (zero2 == 0 || (sum2 + zero2 > sum1 && zero1 == 0)) {
                    return -1;
                } else {
                    return max(sum1 + zero1, sum2 + zero2);
                }
            } else {
                // Try to increase sum1 using its zeros
                if (zero1 == 0 || (sum1 + zero1 > sum2 && zero2 == 0)) {
                    return -1;
                } else {
                    return max(sum1 + zero1, sum2 + zero2);
                }
            }
        }

        return 0LL; // fallback
    }
};