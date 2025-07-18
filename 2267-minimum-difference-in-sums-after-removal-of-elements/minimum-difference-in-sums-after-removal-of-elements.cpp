class Solution {
public:
   
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>minh;
        priority_queue<int>maxh;
        int n=nums.size()/3;
        
        vector<long long>left(nums.size(),0);
        vector<long long>right(nums.size(),0);
         long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
             maxh.push(nums[i]);
            if(maxh.size()>n){
                sum-=maxh.top();
                maxh.pop();
            }
            if(maxh.size()==n){
                left[i]=sum;
            }
           
        }
           sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            
            sum+=nums[i];
            minh.push(nums[i]);

            if(minh.size()>n){
                sum-=minh.top();
                minh.pop();
            }
            if(minh.size()==n){
                right[i]=sum;
            }
        }

        long long mindiff=LLONG_MAX;

      for(int i=0;i<nums.size()-1;i++){
            if(left[i]!=0&&right[i]!=0)
            mindiff=min(mindiff,left[i]-right[i+1]);
        }
      
      
       return mindiff;
    
    }
};