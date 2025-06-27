class Solution {
public:
    int C[26]; int n;
    string res;
    bool compS(string& in_val) {
        int vlen=in_val.length();
        int rlen=res.length();
        if (vlen>rlen) {return true;}
        if (vlen<rlen) {return false;}
        for (int i=0; i<rlen; i++) {
            if (in_val[i]<res[i]) return false;
            if (in_val[i]>res[i]) return true;
        }
        return false;
    }
    bool bruteForceValid(string& s, string& candi, int& k) {
        int cnt=0; int j=0; int clen=candi.length();
        for (int i=0; i<n&&cnt<k; i++) {
            if (s[i]==candi[j]) {j++;}
            if (j==clen) {cnt++;j=0;}
        }
        if (cnt>=k) return true;
        return false;
    }
    void bruteForceOpt(int curl, string candi, string& s, int& k) {
        if (curl==0) return;
        for (int i=25; i>=0; i--) {
            if (C[i]>=k) {
                C[i]-=k; candi+=(char)('a'+i);
                if (bruteForceValid(s,candi,k)) {
                    if (compS(candi)) {res=candi;}
                    bruteForceOpt(curl-1,candi,s,k);
                }
                C[i]+=k; candi.pop_back();
            }
        }
        return;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        n=s.length(); int maxsublen=n/k; res="";
        for (char& ch:s) {C[(int)(ch-'a')]++;}
        bruteForceOpt(maxsublen,"",s,k);
        return res;
    }
};