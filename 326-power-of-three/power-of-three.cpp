class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        if(n<1){
            return false;
        }
        while(n>0){
            if(n==3){
                return true;
            }
            if(n%3==0){
                n=n/3;
                continue;
            }
            return false;
        }
        return true;
    }
};