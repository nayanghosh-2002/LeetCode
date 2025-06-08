class Solution {
    void dfs(int node, vector<int>& ans, int n){
        node  = node*10;
        for(int i = 0;i<=9;i++){
            int newNode = node + i;
            if(newNode<=n){
                ans.push_back(newNode);
                dfs(newNode,ans,n);
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        int i = 1;
        vector<int> ans;
        for(int i = 1;i<=9;i++){
            if(i<=n)
                ans.push_back(i);
                dfs(i,ans,n);
        }
        return ans;
    }
};