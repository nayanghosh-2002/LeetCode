class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i = 0; i < s.length(); i += k)
        {
            string t = s.substr(i, k);
            if(t.length() < k)
            {
                t += string(k - t.length(), fill);
            }
            res.push_back(t);
        }
        return res;
    }
};