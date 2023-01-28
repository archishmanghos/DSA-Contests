#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        s.clear();
    }

    void addNum(int value) {
        s.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        int start = -1, end = -1;
        for (auto it : s) {
            if (start < 0) start = end = it;
            else {
                if (it == end + 1) end += 1;
                else {
                    answer.push_back({start, end});
                    start = end = it;
                }
            }
        }

        answer.push_back({start, end});
        return answer;
    }
};