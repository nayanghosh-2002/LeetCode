class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        unordered_set<int> st;
        for(auto it : words){
            st.insert((int)it.size());
        }

        auto hamming = [&](int i,int j,vector<string> &words){
            int cnt = 0;
            for(int k = 0 ; k < words[i].size() ; k++){
                if(words[i][k] != words[j][k]) cnt++;
            }
            return (cnt != 1) ? false : true;
        };
        int n = groups.size();
        
        vector<vector<int>> hash(11,vector<int>(n,-1));
        int maxi = 0,idx = 0;
        int mxlen = 0;
        for (auto it : st) {
            vector<int> dp(n, 1);
            int maxLen = 0, lastIndex = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (words[i].size() != it) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (groups[i] != groups[j] && words[j].size() == it && hamming(i,j,words) && dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        hash[it][i] = j;
                    }
                }
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    lastIndex = i;
                }
            }
            if(maxLen > mxlen){
                mxlen = maxLen;
                maxi = it;
                idx = lastIndex;
            }
        }

        vector<string> ans;
        while(idx != -1){
            ans.push_back(words[idx]);
            idx = hash[maxi][idx];
        }

        return ans;
    }
};