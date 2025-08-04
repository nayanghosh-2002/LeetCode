class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxLen = 0;
        for (int right = 0, n = fruits.size(); right < n; ++right) {
            ++basket[fruits[right]];
            if(basket.size() > 2){
                while(--basket[fruits[left]]) ++left;
                basket.erase(fruits[left]);
                ++left;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};