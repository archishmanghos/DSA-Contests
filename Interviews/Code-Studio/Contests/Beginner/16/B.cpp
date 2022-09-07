int minimumVisitingCost(vector<int> &a) {
    if (a.size() == 1) return 0;

    sort(a.begin() + 1, a.end());
    int minn = INT_MAX, pos = -1;
    for (int i = 1; i < a.size(); i++) {
        if (abs(a[i] - a[0]) < minn) {
            minn = abs(a[i] - a[0]);
            pos = i;
        }
    }

    int ans1 = minn;
    for (int i = pos + 1; i < a.size(); i++) ans1 += abs(a[i] - a[i - 1]);
    ans1 += abs(a[a.size() - 1] - a[pos - 1]);
    for (int i = pos - 2; i >= 1; i--) ans1 += abs(a[i] - a[i + 1]);

    int ans2 = minn;
    for (int i = pos - 1; i >= 1; i--) ans2 += abs(a[i] - a[i + 1]);
    ans2 += abs(a[1] - a[pos + 1]);
    for (int i = pos + 2; i < a.size(); i++) ans2 += abs(a[i] - a[i - 1]);

    int ans3 = 0;
    for (int i = 1; i < a.size(); i++) ans3 += abs(a[i] - a[i - 1]);

    int ans4 = abs(a[0] - a.back());
    for (int i = a.size() - 2; i >= 1; i--) ans4 += abs(a[i] - a[i + 1]);

    return min(ans1, min(ans2, min(ans3, ans4)));
}