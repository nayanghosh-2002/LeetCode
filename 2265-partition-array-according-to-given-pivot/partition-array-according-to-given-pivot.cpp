class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // Initialize the result vector that will hold our rearranged elements
        vector<int> result;
        
        // Variable to count occurrences of the pivot value
        int count = 0;

        // First pass: Add all elements less than pivot to result
        // and count how many times pivot appears
        for(int num : nums) {
            if(num < pivot) {
                // If number is less than pivot, add it to result immediately
                result.push_back(num);
            }
            else if(num == pivot) {
                // If number equals pivot, increment count
                count++;
            }
        }

        // Add the pivot value to result 'count' number of times
        // This adds all pivot elements at once efficiently
        result.insert(result.end(), count, pivot);

        // Second pass: Add all elements greater than pivot to result
        for(int num : nums) {
            if(num > pivot) {
                // If number is greater than pivot, add it to result
                result.push_back(num);
            }
        }
        
        // Return the final array with elements arranged around pivot
        return result;
    }
};