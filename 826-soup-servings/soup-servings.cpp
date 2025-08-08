class Solution {
public:

    double solve(int a, int b, vector<vector<double>> &dp){
        if(a <= 0 && b > 0)
            return 1;
        if(a <= 0 && b <= 0)
            return 0.5;
        if(a > 0 && b <= 0)
            return 0;
        if(dp[a][b] != -1)
            return dp[a][b];
        double p1 = solve(a-4, b, dp);
        double p2 = solve(a-3, b-1, dp);
        double p3 = solve(a-2, b-2, dp);
        double p4 = solve(a-1, b-3, dp);
        return dp[a][b] = (p1+p2+p3+p4)/4;
    }

    double soupServings(int n) {
        n = ceil(n/25.0);
        if(n > 5000)
            return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        double ans = solve(n, n, dp);
        // bool isMaxN = (1-ans) < 1e-5;
        // cout<<n<<" "<<isMaxN<<endl;
        return ans;
    }
};