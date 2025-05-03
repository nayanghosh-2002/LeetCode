class Solution {
public:
    int solve(vector<int> &tops,vector<int> &bottoms){
        int n = tops.size();
        int ans1 = 0;
        int ans2 = 1;
        int top1 = tops[0];
        int bottoms1 = bottoms[0];
        for(int i=1;i<n;i++){
            if(tops[i]==top1){
                continue;
            }else if(bottoms[i] == top1){
                    ans1++;
            }else{
                ans1=-1;
                break;
            }
        }

        for(int i=1;i<n;i++){
            if(bottoms[0] == tops[i]){
                continue;
            }else if(bottoms[0] == bottoms[i]){
                    ans2++;
            }else{
                ans2 = -1;
                break;
            }
        }
        if(ans1==-1 && ans2==-1){
            return -1;
        }else if(ans1==-1 || ans2==-1){
            return (ans1==-1)?ans2:ans1;
        }else{
            return min(ans1,ans2);
        }
        return 0;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = solve(tops, bottoms);
        int b = solve(bottoms, tops);
        if (a == -1 && b == -1) {
            return -1;
        } else if (a == -1) {
            return b;
        } else if (b == -1) {
            return a;
        } else {
            return min(a, b);
        }
    }
};