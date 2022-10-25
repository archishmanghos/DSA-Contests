class Solution {
public:
    int strtoint (string s) {
        int ans = 0, j = 1;
        while (s.size()) {
            ans += (s.back() - '0') * j;
            j *= 10;
            s.pop_back();
        }

        return ans;
    }

    string inttostr(int x) {
        if (x == 0) return "0";
        string ans = "";
        while (x > 0) {
            ans += (x % 10) + '0';
            x /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int steppingNumbers (int n, int m) {
        queue<string> q;
        for (int i = 1; i < 10; i++) {
            q.push(inttostr(i));
        }

        int ans = n == 0 ? 1 : 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; i++) {
                string num = q.front();
                q.pop();
                if (strtoint(num) >= n) ans += 1;
                if (num.back() > '0') {
                    string x = num + inttostr((num.back() - '0') - 1);
                    if (strtoint(x) <= m) {
                        q.push(x);
                    }
                }
                if (num.back() < '9') {
                    string x = num + inttostr((num.back() - '0') + 1);
                    if (strtoint(x) <= m) {
                        q.push(x);
                    }
                }
            }
        }

        return ans;
    }
};