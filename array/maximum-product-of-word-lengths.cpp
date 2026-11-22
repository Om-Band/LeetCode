
class Solution {
public:
    int maxProduct(vector<string>& words) {

        int n = words.size();
        vector<int> mask(n, 0);
        vector<int> len(n);

        for (int i = 0; i < n; i++) {
            len[i] = words[i].size();

            for (char c : words[i]) {
                mask[i] |= (1 << (c - 'a'));
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int product = len[i] * len[j];

                if (product <= ans)
                    continue;

                if ((mask[i] & mask[j]) == 0) {
                    ans = product;
                }
            }
        }

        return ans;
    }
};
