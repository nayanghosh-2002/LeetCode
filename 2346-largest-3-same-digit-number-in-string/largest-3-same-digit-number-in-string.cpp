class Solution {
public:
    string largestGoodInteger(string nums) {
        int n = nums.length();
        if(n < 3) return "";
        vector<string> vec={"999","888","777","666","555","444","333","222","111","000"};
        for(auto x : vec){
            for(int i = 0 ; i < n - 2 ; i++){
                if(nums.substr(i,3) == x) return nums.substr(i,3);
            }
        }
        return "";
    }
};