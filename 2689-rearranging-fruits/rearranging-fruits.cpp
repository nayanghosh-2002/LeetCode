class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> to_swap;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1; 
            for (int i = 0; i < abs(count) / 2; ++i)
                to_swap.push_back(fruit);
        }

        sort(to_swap.begin(), to_swap.end());

        int global_min = min(
            *min_element(basket1.begin(), basket1.end()),
            *min_element(basket2.begin(), basket2.end())
        );

        long long cost = 0;
        int n = to_swap.size();
        for (int i = 0; i < n / 2; ++i) {
            cost += min(to_swap[i], 2 * global_min);
        }

        return cost;
    }
};