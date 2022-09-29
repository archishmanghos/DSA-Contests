vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    multiset<int> ms;
    for (int i : arr) {
        ms.insert(i);
    }

    vector<int> ans;
    while (k--) {
        auto lb = ms.lower_bound(x);
        auto idx1 = lb, idx2 = lb, idx3 = lb;
        int a = -1e7, b = -1e7, c = -1e7;
        if (idx1 != ms.begin()) {
            idx1--;
            a = *idx1;
        }
        if (idx2 != ms.end()) {
            b = *idx2;
        }
        if (idx3 != ms.end()) {
            idx3++;
            if (idx3 != ms.end()) {
                c = *idx3;
            }
        }

        vector<vector<int>> minn;
        if (a != -1e7) {
            int dist = abs(a - x);
            minn.push_back({dist, a, 0});
        }
        if (b != -1e7) {
            int dist = abs(b - x);
            minn.push_back({dist, b, 1});
        }
        if (c != -1e7) {
            int dist = abs(c - x);
            minn.push_back({dist, c, 2});
        }

        sort(minn.begin(), minn.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        ans.push_back(minn[0][1]);
        if (minn[0][2] == 0) ms.erase(idx1);
        else if (minn[0][2] == 1) ms.erase(idx2);
        else ms.erase(idx3);
    }

    sort(ans.begin(), ans.end());
    return ans;
}