#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }

    bool halvesAreAlike(string s) {
        int cancelOut = 0, i = 0, j = s.size() - 1;
        while (i < j) {
            cancelOut += isVowel(tolower(s[i++]));
            cancelOut -= isVowel(tolower(s[j--]));
        }

        return cancelOut == 0;
    }
};