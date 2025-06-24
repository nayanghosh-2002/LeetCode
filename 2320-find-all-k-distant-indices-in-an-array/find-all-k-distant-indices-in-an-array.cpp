class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> ans;
        vector<int> store;
        for(int i=0; i<n; i++){
            if(nums[i]==key){
                store.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            bool flag=0;
            for(int j=0; j<store.size(); j++){
                if(abs(i-store[j])<=k){
                    flag=1;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        return ans;
    }
};