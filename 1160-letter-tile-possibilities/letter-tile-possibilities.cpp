class Solution {
public:
    void backtrack(unordered_map<char, int>& freq, int& count) {
        for (auto& [ch, num] : freq) {
            if (num > 0) {
                count++;
                num--;
                backtrack(freq, count);
                num++;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) {
            freq[ch]++;
        }
        
        int count = 0;
        backtrack(freq, count);
        return count;
    }
};