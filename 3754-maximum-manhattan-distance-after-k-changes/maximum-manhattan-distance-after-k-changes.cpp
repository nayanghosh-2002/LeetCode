class Solution {
public:
    int maxDistance(string s, int k) {
        
        int n = s.size();
        int mx = 0;
        vector<string>store = {"NW","NE","SW","SE"};

        for(int j=0;j<4;j++){
            string curr = store[j];
            int cnt = 0; int x = 0;int y = 0;
            for(int i=0;i<n;i++){
                char c = s[i];
                if (c == 'N' || c == 'S'){
                    if(cnt < k && c != curr[0]){
                        c = curr[0];
                        cnt++;
                    }
                    if(c == 'N'){
                        y++;
                    }
                    if(c == 'S'){
                        y--;
                    }
                }
                else if(c == 'W' || c == 'E'){
                    if(cnt < k && c != curr[1]){
                        c = curr[1];
                        cnt++;
                    }
                    if(c == 'W'){
                        x--;
                    }
                    if(c == 'E'){
                        x++;
                    }
                }
                mx = max(mx,abs(x)+abs(y));
            }
        }
        return mx;
    }
};