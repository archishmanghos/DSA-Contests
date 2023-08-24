#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int i = 0;
        while (i < words.size()) {
            int sum = 0;
            vector<string> temporary_words;
            while (i < words.size() and sum + words[i].size() < maxWidth) {
                sum += words[i].size() + 1;
                temporary_words.push_back(words[i++]);
            }
            bool notLast = true;
            if (i < words.size() and sum + words[i].size() <= maxWidth) {
                sum += words[i].size();
                temporary_words.push_back(words[i++]);
                notLast = false;
            }

            if (notLast) sum--;

            if (i < words.size()) {
                int n = temporary_words.size(), space = n - 1;
                if (space == 0) {
                    string finalPush = temporary_words[0];
                    while (finalPush.size() < maxWidth) finalPush += ' ';
                    answer.push_back(finalPush);
                    continue;
                }

                int distribution = (maxWidth - sum) / space, remaining_space = (maxWidth - sum) % space;
                string finalPush = temporary_words[0];
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j <= distribution; j++) finalPush += ' ';
                    if (remaining_space) finalPush += ' ';
                    remaining_space = max(0, remaining_space - 1);
                    finalPush += temporary_words[i];
                }

                answer.push_back(finalPush);
            } else {
                string finalPush = temporary_words[0];
                for (int i = 1; i < temporary_words.size(); i++) {
                    finalPush += ' ';
                    finalPush += temporary_words[i];
                }
                while (finalPush.size() < maxWidth) finalPush += ' ';
                answer.push_back(finalPush);
            }
        }

        return answer;
    }
};