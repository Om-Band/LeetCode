
class Solution {
public:
    vector<string> ans;

    void solve(string num, int target, int index,
               long long value, long long prev,
               string path) {

        if (index == num.size()) {
            if (value == target) {
                ans.push_back(path);
            }
            return;
        }

        long long curr = 0;

        for (int i = index; i < num.size(); i++) {

            if (i > index && num[index] == '0')
                break;

            curr = curr * 10 + (num[i] - '0');

            string part = num.substr(index, i - index + 1);

            if (index == 0) {
                solve(num, target, i + 1,
                      curr, curr, part);
            }
            else {
                // Addition
                solve(num, target, i + 1,
                      value + curr, curr,
                      path + "+" + part);

                // Subtraction
                solve(num, target, i + 1,
                      value - curr, -curr,
                      path + "-" + part);

                // Multiplication
                solve(num, target, i + 1,
                      value - prev + prev * curr,
                      prev * curr,
                      path + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};
