class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n == 1) return true; 

        if(n % 2 == 1 || n <= 0) return false;

        int cnt = 0;
        for(int i = 0; i < 32; i++) {

            int x = 1 << i;

            if((x & n ) != 0) {

                cnt++;

                if(i % 2 != 0) {
                    return false;
                }
                
            }

            if(cnt > 1) return false;

        
        }

        return true;
    }
};