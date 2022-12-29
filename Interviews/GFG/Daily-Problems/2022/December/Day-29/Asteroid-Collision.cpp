#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (asteroids[i] < 0) {
                while (ans.size() > 0 and ans.back() > 0 and ans.back() <= -asteroids[i]) {
                    if (ans.back() == -asteroids[i]) {
                        asteroids[i] = 0;
                    }
                    ans.pop_back();
                }

                if (asteroids[i] < 0 and (ans.size() == 0 or ans.back() < 0)) ans.push_back(asteroids[i]);
            } else {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};