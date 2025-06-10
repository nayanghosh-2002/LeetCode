class Solution {
public:
    int maxDifference(string s) {
        
        int mxOdd = 0;
        int mnEven = 102;
        int n = s.length();
        vector<int> charCnt(26, 0);

        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            charCnt[idx]++;
        }

        for(int i = 0; i < 26; i++) {

            if(charCnt[i] == 0) continue;

            if(charCnt[i] % 2 == 0) {
                mnEven = min(charCnt[i], mnEven);
            } else {
                mxOdd = max(charCnt[i], mxOdd);
            }
        }

        return mxOdd - mnEven;
    }
};