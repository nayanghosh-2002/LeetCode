class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            int x=i,n=0,sum=0,s=0;
            while(x){
                sum+= x%10; x/=10; n++;
            }
            if(n%2==1 || sum%2==1) continue; n/=2; x=i;
            while(n--){
                s += x%10; x/=10;
            }
            if(s==(sum-s)) ans++;
            //cout << i << endl;
        }
        return ans;
    }
};