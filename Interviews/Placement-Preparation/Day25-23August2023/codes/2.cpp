#include <bits/stdc++.h>
using namespace std;

int replaceElements(vector<int> &a) {
    int n = a.size();
    if (n & 1) return -1;

    int odd = 0;
    unordered_map<int, int> ump;
    for (int i : a) {
        ump[i]++;
    }

    for (auto key : ump) {
        if (key.second & 1) odd++;
    }

    return (odd / 2);
}