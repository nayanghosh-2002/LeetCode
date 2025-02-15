class Solution {
public:
    int equal(string s, set<int>& st) {
        int i = 0;
        string temp = "";
        int q = 0;
        while (i < s.size()) {
            temp += s[i];
            if (st.find(i) != st.end()) {
                if (temp != "") {
                    int x = stoi(temp);
                    q += x;
                }
                temp = "";
            }
            i++;
        }
        if (temp != "") {
            int x = stoi(temp);
            q += x;
        }
        return q;
    }
    bool solve(int i, string& s, set<int>& st, int j) {
        if (i == s.size()) {
            if (equal(s, st) == j) {
                if (j == 37) {
                    cout << equal(s, st) << " qwertyu" << endl;
                    for (auto xx : st) {
                        cout << xx << " ";
                    }
                    cout << endl;
                }
                return true;
            }
            return false;
        }
        bool flag = false;
        st.insert(i);
        flag |= solve(i + 1, s, st, j);
        st.erase(i);
        flag |= solve(i + 1, s, st, j);
        return flag;
    }

    bool check(int i) {
        int j = i * i;
        string s = to_string(j);
        set<int> st;
        return solve(0, s, st, i);
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i) == true) {
                cout << i << endl;
                sum += (i * i);
            }
        }
        return sum;
    }
};