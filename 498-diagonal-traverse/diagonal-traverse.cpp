class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool goUp = true; // whether we go up at current diagonal

        int m = mat.size();
        int n = mat[0].size();
        int maxSum = m + n - 2; // (m - 1) + (n - 1) max sum of (i + j)
        // diagonals are lines with i + j = constant k

        vector<int> diagonalTraverse((m * n));
        int idx = 0;

        for (int k = 0; k <= maxSum; k++) {
            if (goUp) {
                if (k > m - 1) {
                    int row = m - 1;
                    int col = k - row;
                    while (row >= 0 && row < m && col >= 0 && col < n) {
                        diagonalTraverse[idx++] = mat[row][col];
                        row--; col++;
                    }
                } else {
                    int col = 0;
                    int row = k - col;

                    while (row >= 0 && row < m && col >= 0 && col < n) {
                        diagonalTraverse[idx++] = mat[row][col];
                        row--; col++;
                    }
                }
            } else { // go down
                if (k > n - 1) { // sum more than max column
                    int col = n - 1;
                    int row = k - col;

                    while (row >= 0 && row < m && col >= 0 && col < n) {
                        diagonalTraverse[idx++] = mat[row][col];
                        row++; col--;
                    }
                } else {
                    int row = 0;
                    int col = k - row;

                    while (row >= 0 && row < m && col >= 0 && col < n) {
                        diagonalTraverse[idx++] = mat[row][col];
                        row++; col--;
                    }
                }
                
            }

            goUp = !goUp; // alternate between going up and down
        }
        return diagonalTraverse;
    }
};