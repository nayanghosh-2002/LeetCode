class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();

        int cnt = 1;
        int i = 0, j = 0;

        while(j<n-1){
            if(word[j]==word[j+1]){
                while(word[i]==word[j])j++;
                cnt += (j-i-1);
            }
            else{
                j++;
            }
            i = j;
        }
        return cnt;
    }
};