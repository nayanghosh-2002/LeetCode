#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        if (n < k) return 0;
        int M = a[0];
        for (int v : a) if (v > M) M = v;

        long long total = 1LL * n * (n + 1) / 2;
        long long bad = 0;
        int left = 0, cnt = 0;

        for (int right = 0; right < n; ++right) {
            if (a[right] == M) ++cnt;
            while (cnt >= k) {
                if (a[left] == M) --cnt;
                ++left;
            }
            bad += (right - left + 1);
        }

        return total - bad;
    }
};