class Solution {
public:
    void dfs(vector<int> adj[],int i,int par,vector<int>& v,vector<int> &p){
        p[i]=par;
        for(auto j: adj[i]){
            if(j==par) continue;
            dfs(adj,j,i,v,p);
            v[i]^=v[j];
        }
    }

    // a= xor of all elemnts of component
    // b=xor of rest elements
    // this function will also return XOR of all elemts in component rooted at i

    int dfs2(vector<int> adj[],int i,int par,vector<int>& nums,int &ans,int a,int b){
        int res=nums[i];
        for(auto j: adj[i]){
            if(j==par) continue;
            int z=dfs2(adj,j,i,nums,ans,a,b);
            res^=z;
            int x=z;
            int y=a^x;
            int Max=max(x,max(y,b));
            int Min=min(x,min(y,b));
            ans=min(ans,abs(Max-Min));
        }
        return res;
    }


    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int> adj[n];
        vector<int> p(n,-1);
        vector<int> v(nums.begin(), nums.end());
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // a dfs to make parent array 
        // i assume root to 0 
        dfs(adj,0,-1,v,p);
        int ans=INT_MAX;
        int total=v[0];

        for(auto i: edges){
		 // for [u,v]  u can be parent of v or v can be parent of u ,we have to check for it
                if(p[i[0]]==i[1]){         
                dfs2(adj,i[0],i[1],nums,ans,v[i[0]],total^v[i[0]]);
                dfs2(adj,i[1],i[0],nums,ans,total^v[i[0]],v[i[0]]);
            }else{
                dfs2(adj,i[1],i[0],nums,ans,v[i[1]],total^v[i[1]]);
                dfs2(adj,i[0],i[1],nums,ans,total^v[i[1]],v[i[1]]);
            }

        }
        return ans;
    }
};