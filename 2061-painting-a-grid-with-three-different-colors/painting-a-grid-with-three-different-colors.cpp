class Solution {
public:
    static constexpr int64_t MOD = 1'000'000'007;

    // Convert configuration number to vector of colors
    vector<int> getColors(int config, int m) {
        vector<int> colors(m);
        for (int i = 0; i < m; ++i) {
            colors[i] = config % 3;
            config /= 3;
        }
        return colors;
    }

    // Check if a single column configuration is valid (no adjacent rows same color)
    bool isValidConfig(const vector<int>& colors) {
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i-1]) {
                return false;
            }
        }
        return true;
    }

    // Check if two configurations are compatible (corresponding rows different colors)
    bool isCompatible(const vector<int>& prev, const vector<int>& curr) {
        for (int i = 0; i < prev.size(); ++i) {
            if (prev[i] == curr[i]) {
                return false;
            }
        }
        return true;
    }

public:
    int colorTheGrid(int m, int n) {
        // Step 1: Generate all possible configurations
        int maxConfig = 1;
        for (int i = 0; i < m; ++i) {
            maxConfig *= 3; // 3^m configurations
        }

        // Step 2: Identify valid configurations
        vector<int> validConfigs;
        for (int config = 0; config < maxConfig; ++config) {
            auto colors = getColors(config, m);
            if (isValidConfig(colors)) {
                validConfigs.push_back(config);
            }
        }

        // Step 3: Precompute valid transitions
        vector<vector<int>> transitions(maxConfig);
        for (int curr : validConfigs) {
            auto currColors = getColors(curr, m);
            for (int prev : validConfigs) {
                auto prevColors = getColors(prev, m);
                if (isCompatible(prevColors, currColors)) {
                    transitions[curr].push_back(prev);
                }
            }
        }

        // Step 4: Initialize DP array
        vector<int64_t> dp(maxConfig, 0);
        for (int config : validConfigs) {
            dp[config] = 1; // First column: 1 way per valid config
        }

        // Step 5: Process each column
        for (int j = 1; j < n; ++j) {
            vector<int64_t> newDp(maxConfig, 0);
            for (int curr : validConfigs) {
                int64_t ways = 0;
                // Sum ways from all valid previous configurations
                for (int prev : transitions[curr]) {
                    ways = (ways + dp[prev]) % MOD;
                }
                newDp[curr] = ways;
            }
            dp = move(newDp); // Update dp for next column
        }

        // Step 6: Sum ways for all valid configurations in last column
        int64_t result = 0;
        for (int config : validConfigs) {
            result = (result + dp[config]) % MOD;
        }

        return static_cast<int>(result);
    }
};