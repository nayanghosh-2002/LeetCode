class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        set<int>st;
        vector<int>v;
        int countalpha = 0;
        int count = 0;
        int countal = 0;
        int n = s.size();
        for(char ch:s){
            m[ch]++;
        }
        for(int i=0;i<n;i++){
            m[s[i]]--;
            if(!st.count(s[i])){
                st.insert(s[i]);
                countalpha++;
            }
            if(!m[s[i]]) countal++;
            count++;
            if(countalpha == countal){
                v.push_back(count);
                count=0;
            }
        }
        return  v;
    }
};