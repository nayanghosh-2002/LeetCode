#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> indices;

        for (auto& row : matrix) {
            bool hasZero = false;
            for (int num : row) {
                if (num == 0) {
                    hasZero = true;
                    break;
                }
            } 
            if (hasZero){
                for (int i = 0; i < (floor(row.size() / 2)) + (row.size() % 2); i++) {
                    if (row[i] == 0) indices.push_back(i);
                    if (row[row.size() - i - 1] == 0) indices.push_back(row.size() - i - 1);
                    row[i] = 0;
                    row[row.size() - i - 1] = 0;
                }
            }
        }
        for (auto& row : matrix) {
            for (int i : indices) {
                row[i] = 0;
            }
        }

    }
};