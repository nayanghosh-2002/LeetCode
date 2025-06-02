class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<long long> rat(n,1);
        //left -> right
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                rat[i]=rat[i-1]+1;
            }
        }
        // right -> left 
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rat[i] = max(rat[i], rat[i + 1] + 1);
            }
        }

        long long candies=0;
        //sum the rating array
        for(int i=0;i<n;i++){
            candies+= (long long)rat[i];
        }
        return candies;
    }
};