class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c2 = __builtin_popcount(num2);
        int x = 0; 

        // Traverse bits of num1 from most significant to least significant
        for (int i = 31; i >= 0 && c2 > 0; i--) {
            if (num1 & (1 << i)) { // If bit i in num1 is set
                x |= (1 << i);    // Set bit i in x
                c2--;             // Decrease the count of set bits needed
            }
        }

        // If more bits are needed, set them from least significant to most significant
        for (int i = 0; i <= 31 && c2 > 0; i++) {
            if ((x & (1 << i)) == 0) { // If bit i in x is not set
                x |= (1 << i);        // Set bit i in x
                c2--;                 // Decrease the count of set bits needed
            }
        }

        return x;
    }
};