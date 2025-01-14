class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>cntA(51,0),cntB(51,0);
        vector<int>ans;
        int val=0;
        for(int i=0;i<n;i++){
                cntA[A[i]]++;
                cntB[B[i]]++;
             if(A[i]==B[i]){
                val+=cntA[A[i]]==cntB[B[i]]?1:0;
             }
             else{
                val+=cntA[A[i]]==cntB[A[i]]?1:0;
                val+=cntA[B[i]]==cntB[B[i]]?1:0;
             }
             ans.push_back(val);
             
        }
        return ans;
    }
};