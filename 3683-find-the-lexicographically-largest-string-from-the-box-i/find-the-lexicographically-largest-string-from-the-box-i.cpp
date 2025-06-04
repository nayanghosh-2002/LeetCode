class Solution {
public:
    string answerString(string word, int num) {
        if(num==1)return word;
        string res="";
        for(int i=0;i<word.size();i++)
            res=max(res,word.substr(i,word.size()+1-num));

            return res;
    }
};