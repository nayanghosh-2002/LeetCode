class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();
        // Copying the original array
        vector<int> arr = nums;
        sort(nums.begin(), nums.end());
        // Queue for finding subarrays
        queue<int> temp;
        unordered_map<int, int> parent;
        //  < Parent, it's group >
        unordered_map<int, queue<int>> mp;  // for storing groups
        // first group
        temp.push(nums[0]);
        int par = nums[0]; // parent of first group
        parent[par] = par;
        for(int i=1; i<n; i++) {
            // new group, add previous and set 
            if(nums[i] - nums[i-1] > limit) {
                mp[par] = temp;   // set parent & list
                // renew the list and parent
                temp = queue<int> ();
                par = nums[i];
            }
            parent[nums[i]] = par;
            temp.push(nums[i]);
        }
        // last group is yet to set
        mp[par] = temp;

        vector<int> ans;
        for(int i=0; i<n; i++) {
            int p = parent[arr[i]];
            int elem = mp[p].front();  // first element if the queue will be smallest because we added in sorted format
            mp[p].pop();
            ans.push_back(elem);
        }
        return ans;
    }
};

// 32 - 32 39 40 43 45 51 56
// 70 - 70 73 75

// [73,56,32,70,43,51,40,39,75,45]

// 32 39 40 43 45 51 56 70 73 75

// 0  1  2  3  4 5  6  7  8  9
// 1 81 10 79 36 2 77 12 20 87
// 1 6   

// 8


// 70 32 39 73 40 43 45 51 75 56


// 73-70-75
// 56-51-45-39-40-43-32
//                    i
//           j

// 70 32 39 73 40 43 45

// 70 39 32 73 51 56 43 40 75 45
// 7

// 1 3 5 8 9
// 1 3 5 8 9

// 1 6 7 18 1 2

// 1 7 28 19 10