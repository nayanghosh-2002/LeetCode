class Solution {
public:
    string countAndSay(int n) {

        if(n==1) return "1";
        
        string prevIterationResult = countAndSay(n-1);

        string semiResult = "";

        int m = prevIterationResult.size();

        for(int i=0;i<m;i++){

            char ele = prevIterationResult[i];
            int cnt = 1;

            while(i<m-1 && prevIterationResult[i] == prevIterationResult[i+1]){
                cnt++;
                i++;
            }

            semiResult += to_string(cnt);
            semiResult += string(1,ele);
        }

        return semiResult;
    }
};