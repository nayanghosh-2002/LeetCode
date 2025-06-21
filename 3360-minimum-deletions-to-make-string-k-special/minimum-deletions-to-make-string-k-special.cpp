class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> vec(26,0);
        
        for(auto it : word) vec[it-'a']++;
       
        int n = vec.size();
        sort(vec.begin(),vec.end());
        int car = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            
            int cnt = car;
            for(int j=n-1;j>i;j--){
                if(vec[j] - vec[i] > k) cnt+= vec[j] -vec[i]- k;
                else break;
            }
            
            mini = min ( mini , cnt) ;
            car +=vec[i];
        }
        return mini;
    }
};