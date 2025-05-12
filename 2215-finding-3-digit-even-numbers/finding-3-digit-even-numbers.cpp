class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> hash(10, 0);

        //hash the number of digits + check even
        bool hasEven = false;
        for (int digit : digits) {
            hash[digit]++;
            if (digit % 2 == 0)
                hasEven = true;
        }

        //no even = no game
        if (!hasEven)
            return {};

        //max result space is (998-100)/2 + 1 = 450
        vector<int> result;
        result.reserve(450);

        for (int i = 100; i <= 998; i += 2) {
            //digits are here
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            //can we?
            if (hash[a])
                //then
                hash[a]--;
            else
                //oops
                continue;

            //can we?
            if (hash[b])
                //then
                hash[b]--;
            else {
                //remove side effect, go next
                hash[a]++;
                continue;
            }

            //can we?
            if (hash[c])
                //then
                hash[c]--;
            else {
                //remove side effect, go next
                hash[a]++;
                hash[b]++;
                continue;
            }

            //remove side effect, note result, move next.
            hash[a]++;
            hash[b]++;
            hash[c]++;

            result.push_back(i);
        }

        return result;
    }
};