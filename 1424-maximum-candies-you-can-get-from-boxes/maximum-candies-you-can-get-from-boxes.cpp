class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        queue<int> q;
        vector<int> visit(status.size(), 0);
        for(auto i : initialBoxes) q.push(i);
        int tmp = 1, cnt = 0;

        while(cnt != tmp){ // break the loop if all boxes we can't access 
            int s = q.size();
            tmp = s;
            cnt = 0;
            while(s--){
                int b = q.front();
                q.pop();
                if(status[b] == 0){
                    cnt++; //count boxes we can't access
                    q.push(b);
                    continue;
                }
                ans += candies[b];
                visit[b] = 1;
                for(auto i : keys[b]) status[i] = 1;
                for(auto i : containedBoxes[b]){
                    if(visit[i] == 0){
                        q.push(i);
                    }
                    visit[i] = 1;
                }
            }
        }

        return ans;
    }
};