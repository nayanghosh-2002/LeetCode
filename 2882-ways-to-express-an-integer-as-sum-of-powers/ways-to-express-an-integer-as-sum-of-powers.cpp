class Solution {
public:
    int M = 1e9 + 7;


    int numberOfWays(int x, int p) {

        vector<int> v;
        long long n = 1, pw = pow(n, p);
        while (pw <= x) {
            v.push_back(pw);
            n++;
            
            pw = pow(n, p);
        }
        n = v.size();

           // code of tabulation :->



        vector<int> dp(x + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {

            vector<int> p(x + 1, 0);
            p[0]=1;
            
            for (int j = 1; j <= x; j++) {
                int sm = 0;
                sm = (sm + dp[j]) % M;
                if (v[i] <= j)
                    sm = (sm + dp[j - v[i]]) % M;

                p[j] = sm;
            }
            dp = p;
        }

        return dp[x];
    }
};