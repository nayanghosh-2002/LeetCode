class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int>prefix(n);
        prefix[0]=fruits[0][1];
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+fruits[i][1];
        vector<int>position(n);
        for(int i=0;i<n;i++)position[i]=fruits[i][0];
        if(startPos<=fruits[0][0]){
            if(startPos+k<fruits[0][0])return 0;
            auto itr=upper_bound(position.begin(),position.end(),startPos+k);
            itr--;
            int r=itr-position.begin();
            return prefix[r];
        }
        if(startPos>=fruits[n-1][0]){
            if(startPos-k>fruits[n-1][0])return 0;
            auto itl=lower_bound(position.begin(),position.end(),startPos-k);
            int l=itl-position.begin();
            return prefix[n-1]-((l==0)?0:prefix[l-1]);
        }
        int leftmarker=lower_bound(position.begin(),position.end(),startPos-k)-position.begin();
        auto it=upper_bound(position.begin(),position.end(),startPos);
        it--;
        int starter=it-position.begin();
        int answer=0;
        while(position[leftmarker]<=startPos){
            int cur=0;
            if(2*startPos-2*position[leftmarker]>=k){
                if(leftmarker==0)cur=prefix[starter];
                else cur=prefix[starter]-prefix[leftmarker-1];
            }else{
                auto iit=upper_bound(position.begin(),position.end(),startPos+(k-2*(startPos-position[leftmarker])));
                iit--;
                int rightmarker=iit-position.begin();
                if(leftmarker==0)cur=prefix[rightmarker];
                else cur=prefix[rightmarker]-prefix[leftmarker-1];
            }
            answer=max(answer,cur);
            leftmarker++;
        }
        int rstarter=upper_bound(position.begin(),position.end(),startPos)-position.begin();
        auto ti=upper_bound(position.begin(),position.end(),startPos+k);
        ti--;
        int rrightmarker=ti-position.begin();
        while(position[rrightmarker]>=startPos){
            int cur=0;
            if(2*(position[rrightmarker]-startPos)>=k){
                if(rstarter==0)cur=prefix[rrightmarker];
                else cur=prefix[rrightmarker]-prefix[rstarter-1];
            }else{
                int rleftmarker=lower_bound(position.begin(),position.end(),startPos-(k-2*(position[rrightmarker]-startPos)))-position.begin();
                if(rleftmarker==0)cur=prefix[rrightmarker];
                else cur=prefix[rrightmarker]-prefix[rleftmarker-1];
            }
            answer=max(answer,cur);
            rrightmarker--;
        }return answer;
    }
};