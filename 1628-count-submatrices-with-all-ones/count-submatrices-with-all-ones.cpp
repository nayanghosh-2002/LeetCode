class Solution {
public:
    int oneDArrayCount(vector<int>& vec)
    {
        int consec = 0;
        int res = 0;

        for(int &val : vec)
        {
            if(val == 0)
            {
                consec = 0;
            }
            else
            {
                consec++;
            }

            res += consec;
        }
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        for(int startRow = 0;startRow < n;startRow++)
        {
            vector<int> vec(m,1);
            for(int endRow = startRow;endRow < n;endRow++)
            {
                for(int col = 0;col < m;col++)
                {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                cnt += oneDArrayCount(vec);
            }
        }
        return cnt;
    }
};