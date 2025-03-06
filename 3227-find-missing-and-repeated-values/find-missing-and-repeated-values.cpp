class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>tot;
        for(vector<int>a : grid){
            tot.insert(tot.end(),a.begin(),a.end());
        }
        vector<int>ans;
        sort(tot.begin(),tot.end());
        int b = 0;
        int c = 0;
        int a = 1;
        int i = 0;
        while(a <= *max_element(tot.begin(),tot.end())+1){
            if(find(tot.begin(),tot.end(),a) == tot.end()){
                c+=a;
            }
            if(b != 0 && c != 0){
                break;
            }
            if(tot[i] == tot[i+1]){
                b+=tot[i];
            }   
            a++;
            i++;
            
        }
        ans.push_back(b);
        ans.push_back(c);
        return ans;
    }
};