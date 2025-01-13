class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        
        int ans = 0;
        for(auto ele : m){
            int x = ele.second;
            if(x<3) ans += x;
            else{
                if(x%2==0) ans += 2;
                else ans++;
            }
        }
        return  ans;
    }
};