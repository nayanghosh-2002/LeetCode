class Solution {
public:
    int dp[1005][1005];
    int n;
    int f(vector<vector<int>>&grid,int x,int y){
        if(x<0 or y<0 or x>=n or y>=n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 0;
        if(x==y){
            ans = max(ans,f(grid,x+1,y+1));
        }
        else if(x==y-1){
            ans = max({ans,f(grid,x+1,y+1),f(grid,x+1,y)});
        }
        else{
            ans = max(ans,f(grid,x+1,y-1));
            ans = max(ans,f(grid,x+1,y));
            ans = max(ans,f(grid,x+1,y+1));
        }
        return dp[x][y] = grid[x][y]+ans;
    }
    int g(vector<vector<int>>&grid,int x,int y){
        if(x<0 or y<0 or x>=n or y>=n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 0;
        if(x==y){
            ans = max(ans,g(grid,x+1,y+1));
        }
        else if(x-1==y){
            ans = max({ans,g(grid,x+1,y+1),g(grid,x,y+1)});
        }
        else{
            ans = max(ans,g(grid,x-1,y+1));
            ans = max(ans,g(grid,x,y+1));
            ans = max(ans,g(grid,x+1,y+1));
        }
        return dp[x][y] = grid[x][y]+ans;
    }
    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += grid[i][i];
            grid[i][i] = 0;
        }
        ans += f(grid,0,n-1)+g(grid,n-1,0);
        return ans;
    }
};