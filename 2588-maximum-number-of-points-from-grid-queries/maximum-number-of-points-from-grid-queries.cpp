class Solution {
 #define pi pair<int,pair<int,int>>
 bool isValid(int i,int j,int n,int m){
    return i>=0 && j>=0 && i<n && j<m;
 }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
         int n = grid.size();
         int m = grid[0].size();
         int q = queries.size();
         vector<int>ans(q);
         vector<pair<int,int>>val(q);
         for(int i=0;i<q;i++)
         val[i] = {queries[i],i};
        
        sort(val.begin(),val.end());

        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};

        int cnt =0;
       for(int i=0;i<q;i++){
          while(!pq.empty() && pq.top().first < val[i].first){
               cnt++;
               auto it = pq.top();
               pq.pop();
               int r = it.second.first;
               int c = it.second.second;
            for(int j=0;j<4;j++){
                int nr = r+dr[j];
                int nc = c+dc[j];
                if(isValid(nr,nc,n,m) && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({grid[nr][nc],{nr,nc}});
                }
            }
          }
          ans[val[i].second] = cnt;
       }
       return ans;
    }
};