#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int answer = 0;
        for (string s : details) {
            int age = (s[11] - '0') * 10 + (s[12] - '0');
            answer += age > 60;
        }

        return answer;
    }
};