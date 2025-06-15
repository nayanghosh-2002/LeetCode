class Solution {
public:
    int maxDiff(int num) {
    string big = to_string(num);
    string small = to_string(num);

    int maxi = INT_MIN , mini = INT_MAX , cnt = 0;
    maxi = big[0];
    mini = big[0];

    for(auto it:small){
        if(it == maxi)
        cnt++;
    }

    int i = 0;
    while(i < big.size() && big[i] == '9'){
        i++;
    }
    mini = big[i];

    for(auto& it:big){
        if(it == mini)
        it = '9';
    }

    i = 0;
    while(i < big.size() && (small[i] == '1' || small[i] == '0')){
        i++;
    }
    maxi = small[i];

    string t = small;
    for(auto& i:small){
        if(i == maxi){
        if(cnt == big.size())
        i = '1';
        else if(t[0] == '1')
        i = '0';
        else
        i = '1';
        }
    }

    int a = stoi(big);
    int b = stoi(small);

    return a-b;    
    }
};