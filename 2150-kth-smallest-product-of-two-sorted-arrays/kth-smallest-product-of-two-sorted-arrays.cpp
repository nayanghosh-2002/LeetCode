class Solution {
public:
    long long kthSmallestProduct(vector<int>& A, vector<int>& B, long long k) {
        int64_t left = -1e10, right = 1e10;
        size_t neg_cnt = lower_bound(A.begin(), A.end(), 0) - A.begin();

        while (left <= right) {
            int64_t mid = left + (right - left) / 2;
            if (countLE(A, B, mid, neg_cnt) >= k) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

private:
    long long countLE(const vector<int>& A, const vector<int>& B, int64_t x, size_t neg_cnt) {
        long long cnt = 0;
        int l = 0, r = B.size() - 1;

        for (int i = (x >= 0 ? (int)neg_cnt - 1 : 0);
             x >= 0 ? i >= 0 : i < (int)neg_cnt;
             i += (x >= 0 ? -1 : 1)) {
            while (l < B.size() && (int64_t)A[i] * B[l] > x) ++l;
            cnt += B.size() - l;
        }

        for (int i = (x >= 0 ? (int)neg_cnt : (int)A.size() - 1);
             x >= 0 ? i < A.size() : i >= (int)neg_cnt;
             i += (x >= 0 ? 1 : -1)) {
            if (A[i] == 0) { if (x >= 0) cnt += B.size(); continue; }
            while (r >= 0 && (int64_t)A[i] * B[r] > x) --r;
            cnt += r + 1;
        }

        return cnt;
    }
};