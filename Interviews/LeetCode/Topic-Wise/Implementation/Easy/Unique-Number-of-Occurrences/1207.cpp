#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> cnt(2005, 0);
        for (int i = 0; i < arr.size(); i++) {
            cnt[arr[i] + 1000] += 1;
        }

        set<int> s;
        int elements = 0;
        for (int i = 0; i <= 2000; i++) {
            if (cnt[i] > 0) {
                s.insert(cnt[i]);
                elements += 1;
            }
        }

        return elements == (int)s.size();
    }
};