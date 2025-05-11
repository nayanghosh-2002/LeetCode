class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int checker = 0;

        for (int i = 0; i < arr.size(); ++i){
            arr[i] % 2 != 0 ? checker++: checker = 0;
            
            if (checker == 3) return true;
        }

        return false;
    }
};