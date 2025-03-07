vector<bool> fun(long long n){
    vector<bool>v1(n+1,1);

    v1[1]=0;

    for(long long i=2;i<=n;i++){
      if(v1[i]==1){
         for(long long j=i*i;j<=n;){
             v1[j]=0;
             j+=i;
         }
      }

    }

    return v1;
  }


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>v1=fun(1e6);

        vector<int>ans;


        vector<int>nums;

        for(int i=left;i<=right;i++){
             if(v1[i]==1){
                nums.push_back(i);
             }
        }

        int diff=0;
        int a=-1;
        int b=-1;

        int m=INT_MAX;

        if(nums.size()==1 || nums.size()==0) return {a,b};

        //for(auto a:nums) cout<<a<<" ";

        

        for(int i=0;i<nums.size()-1;i++){
           diff=nums[i+1]-nums[i];
           if(m>diff){
            m=diff;
            a=nums[i];
            b=nums[i+1];
           }
           if(diff<=2) break;
        }


        

        return {a,b};
    }
};