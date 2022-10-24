class Solution {
public:
    void helper (int idx, string s, int &ans, vector<string> &arr) {
        if (idx < 0) {
            if (s.size() > ans) {
                ans = s.size();
            }
            return;
        }

        helper (idx - 1, s, ans, arr);
        vector<int> cnt(26, 0);
        bool ok = true;
        for (char c : s) {
            cnt[c - 'a'] += 1;
            ok &= cnt[c - 'a'] == 1;
        }

        for (char c : arr[idx]) {
            cnt[c - 'a'] += 1;
            ok &= cnt[c - 'a'] == 1;
        }

        if (ok) {
            helper (idx - 1, s + arr[idx], ans, arr);
        }
    }
    int maxLength(vector<string>& arr) {
        int ans = 0, n = arr.size();
        helper (n - 1, "", ans, arr);
        return ans;
    }
};