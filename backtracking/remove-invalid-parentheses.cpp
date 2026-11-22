
class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(')
                count++;
            else if (c == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    void solve(string s, int start, int left, int right) {

        if (left == 0 && right == 0) {
            if (isValid(s))
                st.insert(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {

            if (i > start && s[i] == s[i - 1])
                continue;

            if (s[i] != '(' && s[i] != ')')
                continue;

            string t = s.substr(0, i) + s.substr(i + 1);

            if (s[i] == '(' && left > 0)
                solve(t, i, left - 1, right);

            if (s[i] == ')' && right > 0)
                solve(t, i, left, right - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, left, right);

        return vector<string>(st.begin(), st.end());
    }
};
