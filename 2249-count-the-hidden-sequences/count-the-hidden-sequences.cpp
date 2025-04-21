class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {
        int n = difference.size();
        int band = upper - lower;
        long long mina = 0;
        long long maxa = 0;
        long long val = 0;
        for(int i=0;i<n;i++){
            val = val + difference[i];
            maxa = max(maxa,val);
            mina = min(mina,val);
        }
        int diff = maxa - mina;
        if(diff > band) return 0;
        return band - diff + 1;
    }
};