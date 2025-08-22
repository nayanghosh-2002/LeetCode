class Solution {
public:
    int minimumArea(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int left=m,right=-1;
        int up=n,down=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]){
                    left=min(left,j);
                    right=max(right,j);
                    up=min(up,i);
                    down=max(down,i);
                }
            }
        }
    return (right-left+1)*(down-up+1);
    }
};