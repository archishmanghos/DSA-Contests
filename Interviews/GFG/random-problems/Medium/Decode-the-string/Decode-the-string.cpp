class Solution {
public:
    int sttoi(string s) {
        int j = 1, ans = 0;
        while (s.size() > 0) {
            ans += ((s.back() - '0') * j);
            s.pop_back();
            j *= 10;
        }

        return ans;
    }
    string decodedString(string s) {
        vector<string> v1;
        vector<int> v2;
        string ans = "", num = "", st = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] >= '0' and s[i] <= '9') {
                if (st.size() > 0) {
                    if (v1.size() < v2.size()) {
                        v1.push_back(st);
                    } else {
                        v1.back() += st;
                    }
                }
                st = "";
                num += s[i];
            } else if (s[i] == '[') {
                v2.push_back(sttoi(num));
                num = "";
            } else if (s[i] == ']') {
                if (st.size() > 0) {
                    if (v1.size() < v2.size()) {
                        v1.push_back(st);
                    } else {
                        v1.back() += st;
                    }
                }
                st = "";
                string temp = "";
                for (int j = 1; j <= v2.back(); j++) {
                    temp += v1.back();
                }

                v2.pop_back();
                v1.pop_back();
                if (v1.size() > 0) {
                    v1.back() += temp;
                } else {
                    v1.push_back(temp);
                }
            } else {
                st += s[i];
            }
            i += 1;
            if (v2.size() == 0 and v1.size()) {
                ans += v1.back();
                v1.pop_back();
            }
        }

        return ans;
    }
};