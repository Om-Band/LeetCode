
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            int curr = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > curr) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);

        int ans = 0;

        for (int i = 0; i < m; i++) {

            // Update histogram heights
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }

            // Calculate largest rectangle
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
