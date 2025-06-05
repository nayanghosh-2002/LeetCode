class Solution {
public:
    vector<vector<int>> adj = vector<vector<int>>(26);

    char bfs(char c) {
        int node = c - 'a';

        queue<int> q;
        q.push(node);

        vector<bool> vis(26, false);

        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            vis[temp] = true;

            if (temp < node) node = temp;

            for (auto it : adj[temp]) {
                if (!vis[it]) {
                    q.push(it);
                }
            }
        }

        return (char)(node + 'a');
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        for (int i = 0; i < n; i++) {
            char a1 = s1[i];
            char a2 = s2[i];

            adj[a1 - 'a'].push_back(a2 - 'a');
            adj[a2 - 'a'].push_back(a1 - 'a');
        }

        vector<char> Smallest(26);

        for(int i=0;i<26;i++){
            char c = char(i+'a');
            char b = bfs(c);
            Smallest[i] = b;
        }

        for (int i = 0; i < baseStr.size(); i++) {
            char t = baseStr[i];
            char temp = Smallest[t-'a'];
            baseStr[i] = temp;
        }

        return baseStr;
    }
};