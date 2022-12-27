#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < capacity.size(); i++) {
            pq.push(capacity[i] - rocks[i]);
        }

        int ans = 0;
        while (!pq.empty()) {
            int k = pq.top();
            pq.pop();
            if (k <= additionalRocks) additionalRocks -= k, ans += 1;
            else return ans;
        }

        return ans;
    }
};