class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> vec(501 , 0); 
        for(int i : nums){
            vec[i]++ ; 
        }
        for(int i : vec){
            if((i )%2){
                return false ; 
            }
        }
        return true ; 
    }
};