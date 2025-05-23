typedef long long ll;
class Solution {
public:
    // left: greater or equal
    // right: greater
    ll mod = 1e9 + 7;
    ll myPow(ll a, ll b) {
        ll res = 1;
        while (a) {
            if (a & 1) res = (res * b) % mod;
            a = a >> 1;
            b = b * b % mod;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prime(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            int num = nums[i];
            for (int j = 2; j * j <= num; j++) {
                cnt += (num % j) == 0;
                while ((num % j) == 0) num /= j;
            }
            if (num != 1) cnt += 1;
            prime[i] = cnt;
        }
        unordered_map<int, int> leftMap;
        unordered_map<int, vector<int>> rightMap;
        for (int i = n - 1; i >= 0; i--) {
            rightMap[prime[i]].push_back(i);
        }

        vector<pair<ll, ll>> record;
        for (ll i = 0; i < n; i++) {
            rightMap[prime[i]].pop_back();
            ll leftLen = i + 1;
            for (int j = prime[i]; j <= 10; j++)
                if (leftMap.count(j))
                    leftLen = min(leftLen, i - leftMap[j]);
            ll rightLen = n - i;
            for (int j = prime[i] + 1; j <= 10; j++)
                if (rightMap.count(j) && rightMap[j].size() > 0)
                    rightLen = min(rightLen, rightMap[j].back() - i);
            record.push_back({nums[i], leftLen * rightLen});
            leftMap[prime[i]] = i;
        }
        sort(record.begin(), record.end(), greater<>());

        ll ans = 1;
        for (auto &x: record) {
            ll tmp = myPow(min(x.second, 1ll * k), x.first);
            ans = (ans * tmp) % mod;
            k -= x.second;
            if (k <= 0) break;
        }
        return ans;
    }
};