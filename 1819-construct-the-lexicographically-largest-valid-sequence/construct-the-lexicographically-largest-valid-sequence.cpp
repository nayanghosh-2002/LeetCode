class Solution {
public:
    vector<int> vec, ans;
    int sz;
    bool isFound = false;
    void solve(int ind){
        // cout<<ind<<endl;
        // for(int a: ans){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        if(ind==ans.size()){
            isFound=true;
            for(auto v:vec)
                if(v!=0){
                    isFound=false;
                    break;
                }
            return;
        }
        if(ans[ind]!=0){
            solve(ind+1);
            return;
        }
        for(int i=sz ; i>0 && !isFound ; i--){
            if(i==1 && vec[i]>0){
                ans[ind]=1;
                vec[i]--;
                solve(ind+1);
                if(isFound) break;
                vec[i]++;
                ans[ind]=0;
            }
            else if(vec[i]>0 && (ind+i)<ans.size() && ans[ind+i]==0){
                ans[ind]=i;
                ans[ind+i] = i;
                vec[i]-=2;
                solve(ind+1);
                if(isFound) break;
                ans[ind]=0;
                ans[ind+i] = 0;
                vec[i]+=2;
            }
        }
    }
    vector<int> constructDistancedSequence(int n) {
        vec.assign(n+1,2);
        vec[1]=1;
        vec[0]=0;
        sz=n;
        ans.assign(2*n-1,0);
        solve(0);
        return ans;
    }
};