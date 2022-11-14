class Solution {
   public:
    int numberOfSubsequences(string S, string W) {
        int i = 0, ans = 0;

        while (i < S.size()) {
            int k = 0;
            for (int j = i; j < S.size(); j++) {
                if (W[k] == S[j]) {
                    if (k == 0)
                        i = j + 1;

                    k++;
                    S[j] = '-1';
                }
                if (k == W.size())
                    break;
            }

            if (k == W.size())
                ans++;
            else
                break;
        }

        return ans;
    }
};