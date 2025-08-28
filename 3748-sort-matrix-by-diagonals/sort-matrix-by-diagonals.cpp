class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &ele:mp){
            if(ele.first<0) sort(ele.second.rbegin(),ele.second.rend()); 
            else sort(ele.second.begin(),ele.second.end());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};