class Solution {
   public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26, 0);
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a'] += 1;
                int maxx = 0, minn = 1000;
                for (int k = 0; k < 26; k++) {
                    maxx = max(maxx, cnt[k]);
                    if (cnt[k] > 0) {
                        minn = min(minn, cnt[k]);
                    }
                }

                ans += maxx - minn;
            }
        }

        return ans;
    }
};