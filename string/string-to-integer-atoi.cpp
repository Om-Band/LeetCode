class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // Ignore leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Convert string to integer
        long long ans = 0;

        while (i < n && isdigit(s[i])) {

            ans = ans * 10 + (s[i] - '0');

            // Check overflow
            if (sign * ans >= INT_MAX) {
                return INT_MAX;
            }

            if (sign * ans <= INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};