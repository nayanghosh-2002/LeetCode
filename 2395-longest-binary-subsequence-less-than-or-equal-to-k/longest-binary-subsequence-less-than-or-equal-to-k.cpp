struct Solution {
  uint longestSubsequence(const string& s, uint k) {
    uint n=s.size(), num1 = count(s.begin(), s.end(), '1'), res=n-num1, val=0, pow2=1;
    for (int j=n-1; j>=0 and num1>0 and k>=pow2; --j, pow2*=2) if (s[j]=='1') {
      k-=pow2;
      ++res;
      --num1;
    }
    return res;
  }
};