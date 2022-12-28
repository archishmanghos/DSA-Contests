#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int i : piles) pq.push(i);

        while (!pq.empty() and k--) {
            int x = pq.top();
            pq.pop();
            x = (x + 1) / 2;
            if (x) pq.push(x);
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};