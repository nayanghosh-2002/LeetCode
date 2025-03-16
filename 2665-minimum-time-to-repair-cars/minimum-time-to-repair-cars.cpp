class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long)ranks[0] * cars * cars;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long repaired = 0;
            
            for (int r : ranks) {
                repaired += sqrt(mid / r);
                if (repaired >= cars) break;
            }
            
            if (repaired >= cars) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};