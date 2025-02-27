class Solution {
public:
    int n ;
    int solve(int i, int j, int next, vector<int>&arr,unordered_map<int,int>&mp){
        if(i>=n || j>= n)
            return 0;
        int len = 0;
        if(mp.find(next) != mp.end()){
           len += 1 + solve(j,mp[next],arr[j]+arr[mp[next]],arr,mp);
        }        
        return len;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        unordered_map<int,int>mp; // element->index
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        int maxLen = 0;
        for(int i=0; i<n-2;i++){
            for(int j=i+1; j<n-1;j++){
                maxLen = max(maxLen,2+solve(i,j,arr[i]+arr[j],arr,mp));
            }
        }  // if the final len is coming less than 2 than it must not possible
        // because it is mentioned already that subsequence size is minimum is 3.
        return maxLen <= 2 ? 0 : maxLen ;
    }
};