class Solution {
public:
int M = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        vector<int> hash(26,0);
        for(auto str:s) hash[str-'a']++;
        for(int i=0;i<t;i++){
        vector<int> temp(26,0);
            for(int i=0;i<26;i++){
                if(i==25){
                   temp[0]=(temp[0]+hash['z'-'a'])%M;
                  temp[1]=(temp[1]+hash['z'-'a'])%M;
                }
                else{
                    temp[i+1]=(hash[i] + temp[i+1])%M ;
                  
                }

            }
            hash = temp;
        }
        long long cnt = 0;
        for(auto freq:hash){
      cnt=(cnt+freq)%M;  }
 
 return cnt;
    }
};