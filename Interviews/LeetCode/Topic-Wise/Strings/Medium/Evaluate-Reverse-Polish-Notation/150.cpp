#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getInt (string x) {
        int till = 0, ans = 0, j = 1;
        if (x[0] == '-') {
            till = 1;
        }

        while (x.size() > till) {
            ans += (x.back() - '0') * j;
            x.pop_back();
            j *= 10;
        }

        return (till == 1 ? -ans : ans);
    }

    bool ifOperator (string x) {
        return x == "+" or x == "-" or x == "*" or x == "/";
    }

    long getValue (int x1, int x2, char op) {
        long ans = -1;
        switch (op) {
        case '+':
            ans = x1 + x2;
            break;
        case '-':
            ans = x1 - x2;
            break;
        case '*':
            ans = 1l * x1 * x2;
            break;
        default:
            ans = x1 / x2;
        }

        return ans;
    }

    int evalRPN(vector<string>& tokens) {
        vector<long> v;
        for (string s : tokens) {
            if (!ifOperator (s)) {
                v.push_back(getInt (s));
            } else {
                int second = v.back();
                v.pop_back();
                int first = v.back();
                v.pop_back();
                v.push_back(getValue (first, second, s[0]));
            }
        }

        return v.back();
    }
};