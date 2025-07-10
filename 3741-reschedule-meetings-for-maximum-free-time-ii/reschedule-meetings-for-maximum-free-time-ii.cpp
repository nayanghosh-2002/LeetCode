class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        // the first cal freeAray is same as problem I
        vector<int> freeArr;

        // the first freeTime of arr will be the
        freeArr.push_back(startTime[0]);
        for (int i = 1; i < startTime.size(); i++) {
            freeArr.push_back(startTime[i] - endTime[i - 1]);
        }
        // and for the last freeTime in arr
        freeArr.push_back(eventTime - endTime[endTime.size() - 1]);

        // now we have free time arr with us

        // for this problem there can be two cases :
        // 1 -> we can directly take any one event and place wherever it can fit
        // either left or right 2 -> or just we can move it left or right so for
        // 1st case we should no that is there any free space available right or
        // left for that we need to compute max free space avaiblt for each
        // index using freeaArray
        int n = freeArr.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);

        // max free space for left
        for (int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i - 1], freeArr[i - 1]);
        }

        // for max space in right
        for (int i = n - 2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i + 1], freeArr[i + 1]);
        }

        // now we have both side max space now we have to traverse on freeArr
        // and note that if we are at freeArr[i] then we have to check for max
        // free space like maxLeftFree[i-1] bz
        // f1 e1 f2 e2 f3 e3 f4 e4 f5 e5 f6 e6 f7 e7
        // e -> events f-> free spaces if i want to check for f4
        // then i cant refer f3 as space bz it is my second case for adajacent
        // we have to check for left from e2 so exclude f3 in code
        // and for right side simply use maxRightFree[i] i.e check right from e4
        int res = 0;
        for (int i = 1; i < n; i++) {
            // duration of each event
            int currEventTime = endTime[i - 1] - startTime[i - 1];

            // first case -> the space is available of size either in left or
            // right (moving completely)
            if (currEventTime <= max(maxRightFree[i], maxLeftFree[i - 1])) {
                res = max(res, freeArr[i - 1] + currEventTime + freeArr[i]);
            }
            // second case - that we have not found space greater or eq to
            // currevvent time (shift left or right)
            res = max(res, freeArr[i - 1] + freeArr[i]);
        }
        return res;
    }
};