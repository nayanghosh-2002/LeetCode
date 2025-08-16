class Solution {
public:
    int maximum69Number (int num) {
        int temp=num;int x=0;
        while(temp!=0){
            int rem=temp%10;
            x=(x*10)+rem;
            temp/=10;
        }
        temp=0;
        bool flag=true;
        while(x!=0){
            int rem=x%10;
            if(rem==6 && flag){
                temp=(temp*10)+9;
                flag=false;
            }
            else temp=(temp*10)+rem;
            x/=10;
        }
        return temp;
    }
};