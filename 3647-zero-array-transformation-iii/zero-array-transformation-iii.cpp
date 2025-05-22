class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<array<int, 2>> maxHeap;
        int nidx = 0, qidx = 0, used = 0, curr = 0;
        vector<int> diff(int(nums.size())+1, 0);
        while(nidx < nums.size()) {
            curr += diff[nidx];
            while(qidx < queries.size() && queries[qidx][0] <= nidx) {
                maxHeap.push({queries[qidx][1], queries[qidx][0]});
                qidx ++;
            }
            while(nums[nidx] > curr) {
                if(!maxHeap.empty() && maxHeap.top()[1] <= nidx && maxHeap.top()[0] >= nidx) {
                    curr ++;
                    diff[maxHeap.top()[0] + 1] -= 1;
                    used ++;
                    maxHeap.pop();
                }
                else if(!maxHeap.empty()) {
                    maxHeap.pop();
                }
                else return -1;
            }
            nidx ++;
        }
        return int(queries.size()) - used;
    }
};