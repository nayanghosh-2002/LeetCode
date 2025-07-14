
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        ListNode*temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int p=0;
        int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            int x=v[i]<<p;
            p+=1;
            ans+=x;
        }
        return ans;
    }
};