class Solution {
public:
    int solve(string& s, char first, char second, int value) {
        stack<char>st;
        int sum = 0;
        for(auto c : s) {
            if(c == second) {
                if(!st.empty() && st.top() == first) {
                    st.pop();
                    sum += value;
                } 
                else  st.push(c);
            } 
            else  st.push(c);
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return sum;
    }
    int maximumGain(string s, int x, int y) {
        int sum = 0;
        if(x > y) {
            sum += solve(s, 'a', 'b', x);
            sum += solve(s, 'b', 'a', y);
        } 
        else{
            sum += solve(s, 'b', 'a', y);
            sum += solve(s, 'a', 'b', x);
        }
        return sum;
    }
};