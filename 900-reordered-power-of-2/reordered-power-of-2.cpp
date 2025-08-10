class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int>save_n;
        long temp=n;
        long  count=0;
        while(temp!=0){
            int a=temp%10;
            save_n[a]++;
            temp=temp/10;
            count*=10;
            count+=9;
        }
        long power=1;
        while(power<=count){
            unordered_map<int,int>save_power;
            temp=power;
            while(temp!=0){
                int a=temp%10;
                save_power[a]++;
                temp=temp/10;
            }
            if(save_power==save_n){
                return true;
            }
            power*=2;
        }
        return false;
    }
};