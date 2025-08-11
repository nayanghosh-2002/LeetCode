class Solution {
public:
   long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) 
            result = (result * base) % mod;
        base = (base * base) % mod; 
        exp >>= 1; 
    }
    return result;
}

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int mod=1e9+7;
        int prev=0;
        for(int i=0;i<31;i++){
            if(n&(1<<i)){
                prev=prev+i;
                power.push_back(prev);
            }
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int f=min(queries[i][0],queries[i][1]);
            int s=max(queries[i][1],queries[i][0]);
           long long exp = power[s] - (f > 0 ? power[f-1] : 0);
            long long a = mod_pow(2, exp, mod); // Fast modular exponentiation
            ans.push_back(a);

        }
        return ans;
    }
};