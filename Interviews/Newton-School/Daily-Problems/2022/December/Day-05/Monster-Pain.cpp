#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    cin >> n;
    vector<int> h(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        pq.push(h[i]);
    }

    while (pq.size() > 1) {
        int newSmall = pq.top();
        pq.pop();
        vector<int> v;
        while (!pq.empty()) {
            int newHealth = pq.top() % newSmall;
            if (newHealth) {
                v.push_back(newHealth);
            }
            pq.pop();
        }

        pq.push(newSmall);
        for (int i = 0; i < v.size(); i++) {
            pq.push(v[i]);
        }
    }

    cout << pq.top();
    return 0;
}