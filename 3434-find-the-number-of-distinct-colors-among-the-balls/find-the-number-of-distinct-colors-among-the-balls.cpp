class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result(queries.size(), 0);
        unordered_map<int, int> colorCount;
        unordered_map<int, int> ballToColor;
        int ball, previousColor, newColor;

        for (int i = 0; i < queries.size(); i++) {
            ball = queries[i][0];
            newColor = queries[i][1];
            previousColor = ballToColor[ball];
            
            if (previousColor != 0) {
                colorCount[previousColor]--;
                if (colorCount[previousColor] == 0) {
                    colorCount.erase(previousColor);
                }
            }

            ballToColor[ball] = newColor;
            colorCount[newColor]++;

            result[i] = colorCount.size();
        }

        return result;
    }
};