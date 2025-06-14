class Solution {
public:
    int minMaxDifference(int num) {
        string n=to_string(num);

        // maximum
        string max_s=(n);
        char c=' ';
        for(int i=0;i<n.length();i++){
            if(n[i]!='9'){
                c=n[i];
                break;
            }
        }
        if(c!= ' '){
            // 9 hi h 
            for(int j=0;j<max_s.length();j++){
            if(max_s[j]==c){
                max_s[j]='9';
            }
        }
        }
        long long max_val = std::stoll(max_s);


        // for minimum value
        string min_s=(n);
        char f=' ';
        for(int i=0;i<n.length();i++){
            if(n[i]!='0'){
                f=n[i];
                break;
            }
        }
        if(f !=' '){
            for(int j=0;j<min_s.length();j++){
                if(min_s[j]==f){
                    min_s[j]='0';
                }
            }
        }
        long long min_val=std::stoll(min_s);
        return max_val-min_val;
    }
};