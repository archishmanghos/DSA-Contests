#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addBinary(string A, string B) {
        string ans = "";
        int carry = 0;
        while (carry > 0 or A.size() > 0 or B.size() > 0) {
            int a, b;
            if (A.size()) {
                a = A.back() - '0';
                A.pop_back();
            } else {
                a = 0;
            }

            if (B.size()) {
                b = B.back() - '0';
                B.pop_back();
            } else {
                b = 0;
            }

            int sum = a + b + carry;
            ans += (sum % 2 ? '1' : '0');
            carry = (sum < 2 ? 0 : 1);
        }

        while (ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};