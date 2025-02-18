class Solution {
public:
    bool recursion(int start, string& pattern, vector<bool>& used, string& res)
    {
        if(start==pattern.size()+1) return true;
        for(int i=1;i<=9;i++){
            if(used[i]==1) continue;
   
            if(start>0){
                if(pattern[start-1]=='I'){
                    int prevval=res[start-1]-'0';
                    if(prevval>i) continue;
                }
                else{
                    int prevval=res[start-1]-'0';
                    if(prevval<i) return false;
                }
            }
            res[start]=(i+'0');
            used[i]=1;
            if(recursion(start+1,pattern,used,res)) return true;
            used[i]=false;
        }
        return false;
    }
    string smallestNumber(string pattern) {
        string res(pattern.size()+1,'1');
        vector<bool>used(10,0);
        recursion(0,pattern,used,res);
        return res;
    }
};