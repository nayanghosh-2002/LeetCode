class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //c m pehle number ka parity (odd/even) store kar rha hu
        //0 => even, 1 => odd
        int c = nums[0]%2;
        
        int odd=0, even=0, both=0;

        //vector nums ko iterate kar rha hu
        for(int num:nums){

            if(num%2==0) 
                even++;
            else 
                odd++;

            //agar current number ki parity (odd/even) c ke barabar h
            //to alternating pattern bana rhe h
            if(num%2 == c){
                both++;
                c=1-c; //next time opposite parity chahiye (flip 0<->1)
            }
        }

        return max(both, max(even,odd));
    }
};