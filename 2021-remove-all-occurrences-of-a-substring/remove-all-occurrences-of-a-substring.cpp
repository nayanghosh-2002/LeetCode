class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int m = part.size();
        
        for (char c : s) {
            res += c;
            if (res.size() >= m && res.substr(res.size() - m) == part) {
                res.erase(res.size() - m);
            }
        }
        return res;
    }
};