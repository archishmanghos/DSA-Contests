#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> v;
        int n = tasks.size();
        for (int i = 0; i < n; i++)
            v.push_back({tasks[i][0], tasks[i][1], i});
        sort(v.begin(), v.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> availableTasks;
        int task = 0, lastProcessTime = 0;
        vector<int> ans;

        while (task < n) {
            if (availableTasks.empty()) {
                ans.push_back(v[task][2]);
                lastProcessTime = v[task][0] + v[task][1];
                task += 1;
            } else {
                vector<int> latestTask = availableTasks.top();
                availableTasks.pop();
                ans.push_back(latestTask[1]);
                lastProcessTime += latestTask[0];
            }

            while (task < n and v[task][0] <= lastProcessTime) {
                availableTasks.push({v[task][1], v[task][2]});
                task += 1;
            }
        }

        while (!availableTasks.empty()) {
            ans.push_back(availableTasks.top()[1]);
            availableTasks.pop();
        }

        return ans;
    }
};