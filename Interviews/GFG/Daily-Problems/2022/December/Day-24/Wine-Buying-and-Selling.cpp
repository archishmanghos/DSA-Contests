#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int wineSelling(vector<int>& Arr, int N) {
        queue<vector<int>> sell, buy;
        long long int ans = 0;
        for (int i = 0; i < N; i++) {
            if (Arr[i] > 0) {
                while (Arr[i] > 0 and !sell.empty()) {
                    vector<int> ele = sell.front();
                    sell.pop();
                    int k = min(Arr[i], abs(ele[0]));
                    Arr[i] -= k;
                    ele[0] += k;
                    ans += k * abs(i - ele[1]);
                    if (ele[0]) sell.push(ele);
                }
                if (Arr[i]) buy.push({Arr[i], i});
            } else {
                while (Arr[i] < 0 and !buy.empty()) {
                    vector<int> ele = buy.front();
                    buy.pop();
                    int k = min(abs(Arr[i]), ele[0]);
                    Arr[i] += k;
                    ele[0] -= k;
                    ans += k * abs(i - ele[1]);
                    if (ele[0]) buy.push(ele);
                }
                if (Arr[i]) sell.push({Arr[i], i});
            }
        }

        return ans;
    }
};