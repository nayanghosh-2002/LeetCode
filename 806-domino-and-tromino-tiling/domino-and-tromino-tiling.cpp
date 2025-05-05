vector<vector<int>> dp;
auto x = [] {
    int n = 1e3;
    dp.resize(n + 2, vector<int>(3, 0));
    int a = 0, b = 1, c = 2;
    dp[0][0] = 1;
    int mod = 1e9 + 7;
    /* possible ending shapes
        a.  *   b.  * *    c.  * -
            *       * -        * *
    */
    for (int i = 1; i <= n; i++) {
        // 1.  *    | if ending shape is 'a', then new ending shape will be 'a' at (i)
        //     *    |
        dp[i][a] = (dp[i][a] + dp[i - 1][a]) % mod;
        // 2.  * *  | if ending shape is 'c', then new ending shape will be 'b' at (i)
        //     - -  |
        dp[i][b] = (dp[i][b] + dp[i - 1][c]) % mod;
        // 3.  - -  | if ending shape is 'b', then new ending shape will be 'c' at (i)
        //     * *  |
        dp[i][c] = (dp[i][c] + dp[i - 1][b]) % mod;
        // 4.  * *  | if ending shape is 'a', then new ending shape will be 'a' at (i + 1)
        //     * *  |
        dp[i + 1][a] = (dp[i + 1][a] + dp[i - 1][a]) % mod;
        // 5.  * *  | if ending shape is 'a', then new ending shape will be 'b' at (i + 1)
        //     * -  |
        dp[i + 1][b] = (dp[i + 1][b] + dp[i - 1][a]) % mod;
        // 6.  * -  | if ending shape is 'a', then new ending shape will be 'c' at (i + 1)
        //     * *  |
        dp[i + 1][c] = (dp[i + 1][c] + dp[i - 1][a]) % mod;
        // 7.  * *  | if ending shape is 'c', then new ending shape will be 'a' at (i)
        //     - *  |
        dp[i][a] = (dp[i][a] + dp[i - 1][c]) % mod;
        // 8.  - *  | if ending shape is 'b', then new ending shape will be 'a' at (i)
        //     * *  |
        dp[i][a] = (dp[i][a] + dp[i - 1][b]) % mod;
    }
    return 0;
} ();

class Solution {
public:
    int numTilings(int n) {
        return dp[n][0];
    }
};
