class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        set<pair<int,int>>s;
        int n = grid.size();
        int m = grid[0].size();
        int maxa = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count =0;
                if(grid[i][j] > 0 && !s.count(make_pair(i,j))){
                    s.insert(make_pair(i,j));
                    q.push(make_pair(i,j));
                    // count += grid[i][j];
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        count += grid[curr.first][curr.second];
                        if(curr.first-1>=0 && grid[curr.first-1][curr.second]>0 && !s.count(make_pair(curr.first-1,curr.second))){
                            q.push(make_pair(curr.first-1,curr.second));
                            s.insert(make_pair(curr.first-1,curr.second));
                        } 
                        if(curr.second-1>=0 && grid[curr.first][curr.second-1]>0 && !s.count(make_pair(curr.first,curr.second-1))){
                            q.push(make_pair(curr.first,curr.second-1)); 
                            s.insert(make_pair(curr.first,curr.second-1));
                        } 
                        if(curr.first+1<n && grid[curr.first+1][curr.second]>0 && !s.count(make_pair(curr.first+1,curr.second))){
                            q.push(make_pair(curr.first+1,curr.second)); 
                            s.insert(make_pair(curr.first+1,curr.second));
                        } 
                        if(curr.second+1<m && grid[curr.first][curr.second+1]>0 && !s.count(make_pair(curr.first,curr.second+1))){
                            q.push(make_pair(curr.first,curr.second+1)); 
                            s.insert(make_pair(curr.first,curr.second+1));
                        } 
                    }
                    maxa = max(maxa,count);
                }
            }
        }
        return maxa;
    }
};