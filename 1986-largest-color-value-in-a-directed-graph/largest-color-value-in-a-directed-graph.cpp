class Solution {
public:

    int dfs(int node, vector<int>&visits, vector<int>&recStack, vector<vector<int>>&graph){
        int ans;
        if(recStack[node]){
            ans = 1;
        }
        else if(visits[node]){
            ans = 0;
        }
        else{
            int i, ad;
            visits[node] = 1;
            recStack[node] = 1;
            ans = 0;
            for(i = 0; i<graph[node].size() && !ans; i++){
                ad = graph[node][i];
                ans = dfs(ad, visits, recStack, graph);
            }
            if(!ans){
                recStack[node] = 0;
            }
        }
        return ans;
    }

    int dp(int node, string&colors, vector<vector<int>>&graph, vector<int>&mem, char &find){
        int ans;
        if(mem[node] != -1){
            ans = mem[node];
        }
        else{
            if(!graph[node].size()){
                ans = 0;
                if(colors[node] == find){
                    ans = 1;
                }
            }
            else{
                int i, sum = 0, ad;
                ans = 0;
                if(colors[node] == find){
                    sum = 1;
                }
                for(i = 0; i<graph[node].size(); i++){
                    ad = graph[node][i];
                    ans = max(ans, dp(ad, colors, graph, mem, find)+sum);
                }
            }
            mem[node] = ans;
        }
        return ans;
    }

    int largestPathValue(string &colors, vector<vector<int>>& edges) {
        int i, j, ans = -1, cycle = 0;
        char find;
        vector<vector<int>>graph(colors.size());
        vector<int>visits(colors.size());
        vector<int>recStack(colors.size());
        vector<int>flags(26);
        for(i = 0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        for(i = 0; i<colors.size() && !cycle; i++){
            if(!visits[i] && dfs(i, visits, recStack, graph)){
                cycle = 1;
            }
            flags[colors[i]-'a'] = 1;
        }
        if(!cycle){
            for(i = 0; i<26; i++){
                if(flags[i]){
                    vector<int>mem(colors.size(), -1);
                    find = i + 'a';
                    for(j = 0; j<colors.size(); j++){
                        if(mem[j] == -1){
                            ans = max(ans, dp(j, colors, graph, mem, find));
                        }
                    }
                }
            }
        }
        return ans;
    }
};