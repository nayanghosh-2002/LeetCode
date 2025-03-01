class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int ind=0;ind<nums.size()-1;ind++){ //loop to change the values according to condition
            if(nums[ind]==nums[ind+1]){
                nums[ind]=2*nums[ind+1];
                nums[ind+1]=0;}
        }
        int count=0;   //counting the number of zeroes
         for(int ind=0;ind<nums.size();ind++){
            if(nums[ind]!=0)nums[count++]=nums[ind];
        }
        while(count<nums.size()){ //pushing the zeroes to the end
            nums[count++]=0;
        }
       
        return nums;
    }
};