class Solution {
public:
    string spellCount(int n) {
        string ans = "";
        while (n > 0) {
            ans += (n % 10) + '0';
            n /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string convertToShit(string s) {
        int cnt = 1;
        string ans = "";
        char cur = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == cur) {
                cnt += 1;
            } else {
                ans += spellCount(cnt) + cur;
                cur = s[i];
                cnt = 1;
            }
        }

        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            ans = convertToShit(ans + 'a');
        }

        return ans;
    }
};