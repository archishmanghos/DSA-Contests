#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int answer = -1, low = 1, high = 10000000;
        while (low <= high) {
            int mid = (low + high) / 2;
            auto f = [&]() {
                double totalTime = 0.0;
                for (int i = 0; i < dist.size() - 1; i++) {
                    totalTime += (dist[i] + mid - 1) / mid;
                }
                totalTime += (double) dist.back() / mid;
                return (totalTime <= hour);
            };
            if (f()) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};