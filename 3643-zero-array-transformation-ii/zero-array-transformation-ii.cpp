//"RADHA RADHA"
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int i=0;
        int ans=0;
        int cnt_z=0;
        cout<<"RR";
        for(auto i:nums){
            if(i==0){
               cnt_z++;
            }
        }
        if(cnt_z==n){
                return 0;
            }
            vector<int> prefix(n);
            int idx=0;
        while(i<q){
            int l=queries[i][0],r=queries[i][1],value =queries[i][2];
            if(l<=idx && idx<=r){
                prefix[idx]+=value;
            }
            else
                prefix[l]+=value;
                if(r<idx){
                    i++;
                    continue;
                }
            if(r+1<n){
                prefix[r+1]-=value;
            }
            while(nums[idx]<=prefix[idx]){
                nums[idx]=0;
                idx++;
                if(idx==n){
                    return i+1;
                }
                prefix[idx]+=prefix[idx-1];
            }
            i++;
        }
    
            return -1;
    }
};