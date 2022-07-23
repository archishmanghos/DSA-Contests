#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N; cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++) cin >> heights[i];
    int prevToPrev, prev = 0;
    for (int i = N - 2; i >= 0; i--) {
        int curEnergy;
        if (i < N - 2) curEnergy = min(prev + abs(heights[i + 1] - heights[i]), prevToPrev + abs(heights[i + 2] - heights[i]));
        else curEnergy = prev + abs(heights[i + 1] - heights[i]);
        prevToPrev = prev;
        prev = curEnergy;
    }
    cout << prev;

    return 0;
}