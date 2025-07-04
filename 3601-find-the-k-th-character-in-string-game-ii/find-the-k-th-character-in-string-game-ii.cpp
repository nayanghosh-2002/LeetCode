class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) {
            return 'a';
        }
        long long currIndex = k;
        int changeCounter = 0;
        while (currIndex > 1) {
            int last2 = floor(log2(currIndex - 1));
            currIndex = currIndex - ((long long) 1 << last2);
            changeCounter += operations[last2];
        }

        return 'a' + (changeCounter % 26);

    }
};