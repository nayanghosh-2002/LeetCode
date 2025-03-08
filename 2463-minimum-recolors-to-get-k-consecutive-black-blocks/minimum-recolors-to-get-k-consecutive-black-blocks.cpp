class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int countWhites = 0, minOps = k, n = blocks.length();

        int start = 0, end = 0;

        while(end < k) countWhites += (blocks[end++] == 'W');

        minOps = countWhites;

        while(end < n)
        {
            countWhites += (blocks[end++] == 'W') - (blocks[start++] == 'W');
            minOps = min(minOps,countWhites);
        }

        return minOps;
    }
};