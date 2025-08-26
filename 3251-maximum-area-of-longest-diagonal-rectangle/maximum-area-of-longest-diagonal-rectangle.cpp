class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long maxDim = 0;
        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long diagonal = (pow(dimensions[i][0], 2) +
                                  pow(dimensions[i][1], 2));
            if (diagonal >= maxDim) {
                long long area = dimensions[i][0] * dimensions[i][1];
                if (diagonal == maxDim) {
                    maxArea = max(maxArea, area);
                } else {
                    maxArea = area;
                }
                maxDim = diagonal;
            }
        }
        return maxArea;
    }
};