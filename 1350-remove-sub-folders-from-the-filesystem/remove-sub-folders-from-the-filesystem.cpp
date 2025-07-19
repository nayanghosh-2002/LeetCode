class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> ans;

        for (const auto& it : folder) {
            string curr = it;
            bool found = false;

            while (!curr.empty()) {
                size_t pos = curr.find_last_of('/');
                if (pos == 0) break; 

                curr = curr.substr(0, pos); 
                if (st.find(curr) != st.end()) {
                    found = true;
                    break;
                }
            }

            if (!found) ans.push_back(it);
        }

        return ans;
    }
};