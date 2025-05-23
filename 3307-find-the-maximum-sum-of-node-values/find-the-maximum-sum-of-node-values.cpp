#define ll long long int
class Solution {
public:
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& e) {
        
        int n = nums.size();
        ll ans  = 0;
        ll sum1 = 0;
        ll sum2 = 0;
        vector<ll> x,nx;
        
        for(int i=0;i<n;i++){
            int diff = ( nums[i]^k ) - nums[i];
            
            if( diff >= 0 ){
                x.push_back( diff );
                sum1 += ( nums[i]^k );
            }
            else{
                nx.push_back( abs(diff) );
                sum2 += nums[i];
            }
        }
        
        sort( x.begin() , x.end() );
        sort( nx.begin(), nx.end() );
        
        if( x.size()%2 == 0 ){
            ans = max( ans, sum1+sum2);   
        }
        else{
            
            if( nx.size() )
                ans = max( sum1 + sum2 - x[0] , sum1 + sum2 - nx[0] );
            else
                ans = sum1 + sum2 - x[0];   
        }
        
        return ans;
    }
};