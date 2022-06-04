class Solution {
public:
    long long appealSum(string s) {
        vector<int> lastIndex(26, -1);
        long long ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            ans += (i - lastIndex[s[i] - 'a']) * (n - i);
            lastIndex[s[i] - 'a'] = i;
        }

        return ans;
    }
};