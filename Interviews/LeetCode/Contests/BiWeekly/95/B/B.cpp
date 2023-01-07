#include <bits/stdc++.h>
using namespace std;

class DataStream {
private:
    deque<vector<int>> dq;
    int value, k, idx;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        dq.clear();
        idx = 0;
    }

    bool consec(int num) {
        if (dq.empty() or dq.back()[1] != num) {
            dq.push_back({idx, num});
        }
        if (idx >= k) {
            vector<int> v1 = dq.front();
            dq.pop_front();
            if (dq.size() > 0) {
                vector<int> v2 = dq.front();
                if (v1[0] + 1 < v2[0]) dq.push_front({v1[0] + 1, v1[1]});
            } else {
                dq.push_front({v1[0] + 1, v1[1]});
            }
        }

        vector<int> v = dq.back();
        idx += 1;
        if (v[1] == value and idx - v[0] >= k) return true;
        return false;
    }
};